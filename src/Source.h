//
// Created by valie on 15.06.2023.
//

#pragma once

#include "ISource.h" // интерфейс ISource
#include <vector>
class Source : public ISource {
public:
    Source(std::vector<uint8_t> data);

    bool hasData() const override; // Реализация функции hasData()
    uint8_t readByte() override; // Реализация функции readByte()

private:
    std::vector<uint8_t> data_; // Приватное поле класса, которое хранит вектор данных.
    std::size_t index_; // Приватное поле класса, которое хранит текущий индекс чтения данных.
};
