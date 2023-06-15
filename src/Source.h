//
// Created by valie on 15.06.2023.
//

#pragma once

#include "ISource.h"

class Source : public ISource {
public:
    Source(const std::string& data);

    bool hasData() const override;
    uint8_t readByte() override;

private:
    const std::string& data_;
    std::size_t index_;
};
