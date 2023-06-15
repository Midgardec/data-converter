//
// Created by valie on 15.06.2023.
//

#include "Source.h"

Source::Source(std::vector<uint8_t> data) : data_(data), index_(0) {
    // Конструктор класса Source.
    // Принимает вектор данных в качестве параметра и инициализирует поля data_ и index_
}


bool Source::hasData() const {
    // Реализация метода hasData()
    // Проверяет наличие данных в источнике.
    // Возвращает true, если текущий индекс меньше размера вектора данных, иначе возвращает false
    return index_ < data_.size();
}

uint8_t Source::readByte() {
    // Реализация метода readByte()
    // Считывает байт данных из источника и возвращает его.
    // Увеличивает текущий индекс после чтения
    return data_[index_++];
}
