//
// Created by valie on 15.06.2023.
//

#pragma once
#include <cstdint>
#include <string>

class ISource {
public:
    virtual bool hasData() const = 0; // Чисто виртуальная функция hasData(), которая возвращает булевое значение, указывающее на наличие данных в источнике.
    virtual uint8_t readByte() = 0; // Чисто виртуальная функция readByte(), которая считывает и возвращает байт данных из источника.
};
