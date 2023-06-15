//
// Created by valie on 15.06.2023.
//

#pragma once
#include <cstdio>
#include <string>

class ISink {
public:
    virtual void write(const std::string& data) = 0; // Чисто виртуальная функция для записи данных в sink
};