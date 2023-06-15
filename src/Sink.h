//
// Created by valie on 15.06.2023.
//

#pragma once

#include "ISink.h"

class Sink : public ISink {
public:
    void write(const std::string& data) override;
};
