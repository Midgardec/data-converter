//
// Created by valie on 15.06.2023.
//

#pragma once

#include "ISink.h"// интерфейс ISink

class Sink : public ISink {
public:
    void
    write(const std::string &data) override; //Реализация виртуальной функции write из интерфейса ISink.
    // Принимает const std::string& data в качестве аргумента, представляющего данные для записи в sink.

};
