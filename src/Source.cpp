//
// Created by valie on 15.06.2023.
//

#include "Source.h"

Source::Source(const std::string& data) : data_(data), index_(0) {}

bool Source::hasData() const {
    return index_ < data_.size();
}

uint8_t Source::readByte() {
    return data_[index_++];
}
