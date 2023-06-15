//
// Created by valie on 15.06.2023.
//

#pragma once
#include <cstdint>
#include <string>

class ISource {
public:
    virtual bool hasData() const = 0;
    virtual uint8_t readByte() = 0;
};
