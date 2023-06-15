//
// Created by valie on 15.06.2023.
//

#pragma once

#include "ISource.h"
#include <vector>
class Source : public ISource {
public:
    Source(std::vector<uint8_t> data);

    bool hasData() const override;
    uint8_t readByte() override;

private:
    std::vector<uint8_t> data_;
    std::size_t index_;
};
