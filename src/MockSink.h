//
// Created by valie on 15.06.2023.
//

#pragma once

#include <gmock/gmock.h>
#include "ISink.h"

class MockSink : public ISink {
public:
    MOCK_METHOD1(write, void(const std::string&));
    // Мок-объект класса Sink, реализующий интерфейс ISink.
    // Имеет мок-метод write, принимающий строку данных
};
