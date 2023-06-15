//
// Created by valie on 15.06.2023.
//

#include "DataConverter.h"
#include <iostream>

DataConverter::DataConverter(ISource *source, ISink *sink) : source_(source), sink_(sink), running_(false) {}

void DataConverter::start() {
    if (!running_.exchange(true)) {
        thread_ = std::thread(&DataConverter::run, this);
    }
}

void DataConverter::stop() {
    if (running_.exchange(false)) {
        thread_.join();
    }
}

void DataConverter::run() {
    while (running_) {
        if (!source_->hasData()) {
            std::this_thread::yield();
            continue;
        }

        uint8_t byte = source_->readByte();
        uint8_t type = (byte & 0xC0) >> 6;
        uint8_t data = byte & 0x3F;

        std::string convertedData;

        switch (type) {
            case 0b00:
                convertedData = std::to_string(static_cast<uint8_t>(data));
                break;
            case 0b01:
                convertedData = std::to_string(static_cast<int8_t>(data));
                break;
            case 0b10:
                if (data < 26) {
                    convertedData = static_cast<char>('a' + data);
                } else if (data < 52) {
                    convertedData = static_cast<char>('A' + data - 26);
                } else {
                    convertedData = "Invalid data";
                }
                break;
            default:
                convertedData = "Invalid type";
                break;
        }

        sink_->write(convertedData);
    }
}
