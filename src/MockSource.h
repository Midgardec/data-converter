//
// Created by valie on 15.06.2023.
//
#pragma once

#include <gmock/gmock.h>
#include "ISource.h"

class MockSource : public ISource {
public:
    MOCK_CONST_METHOD0(hasData, bool());
    MOCK_METHOD0(readByte, uint8_t());
};
