//
// Created by valie on 15.06.2023.
//

#include "DataConverter.h"
#include <iostream>

DataConverter::DataConverter(ISource *source, ISink *sink) : source_(source), sink_(sink), running_(false) {
    // Конструктор класса DataConverter, инициализирует указатели на источник и приемник, а также устанавливает флаг running в false
}

void DataConverter::start() {
    if (!running_.exchange(true)) {
        thread_ = std::thread(&DataConverter::run, this);
    }

    // Запускает процесс конвертации данных только если флаг running установлен в false.
    // Создает поток, в котором вызывается метод run
}

void DataConverter::stop() {
    if (running_.exchange(false)) {
        thread_.join();
    }
    // Останавливает процесс конвертации данных только если флаг running установлен в true.
}

void DataConverter::run() {
    while (running_) {
        if (!source_->hasData()) {
            std::this_thread::yield();
            continue;
            // Если в источнике данных нет новых байтов, выполняется переключение контекста и продолжение цикла
        }

        uint8_t byte = source_->readByte();// Чтение байта из источника данных
        uint8_t type = (byte & 0xC0) >> 6;// Извлечение типа данных маской 0x11000000
        uint8_t data = byte & 0x3F;      // Извлечение самих данных из байта маской 0x00111111

        std::string convertedData; // Переменная для хранения конвертированных данных

        switch (type) {
            case 0b00:
                // Если тип данных 0b00, конвертировать данные в беззнаковое целое число
                convertedData = std::to_string(static_cast<uint8_t>(data));
                break;
            case 0b01:
                // Если тип данных 0b01, конвертировать данные в знаковое целое число
                convertedData = std::to_string(static_cast<int8_t>(data));
                break;
            case 0b10:
                // Если тип данных 0b10, конвертировать данные в символ латинского алфавита
                if (data < 26) {// Строчные буквы
                    convertedData = static_cast<char>('a' + data);
                } else if (data < 52) {// Заглавные буквы
                    convertedData = static_cast<char>('A' + data - 26);
                } else {// НЕ буквы
                    convertedData = "Invalid data";
                }
                break;
            default:
                // Обработка невалидного типа данных
                convertedData = "Invalid type";
                break;
        }

        sink_->write(convertedData); // Запись конвертированных данных в приемник
    }
}
