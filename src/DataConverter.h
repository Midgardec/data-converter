//
// Created by valie on 15.06.2023.
//

#pragma once

#include <atomic>
#include <thread>
#include "ISource.h"
#include "ISink.h"

class DataConverter {
public:
    DataConverter(ISource* source, ISink* sink);
    // Конструктор класса DataConverter, принимающий указатели на источник и приемник

    void start();// Запускает процесс конвертации данных
    void stop(); // Останавливает процесс конвертации данных

private:
    ISource* source_;// Указатель на источник данных
    ISink* sink_;// Указатель на приемник данных
    std::atomic<bool> running_;// Атомарная переменная для отслеживания состояния работы процесса конвертации
    std::thread thread_;// Поток, в котором выполняется процесс конвертации

    void run();// Вспомогательная функция, выполняющая фактическую конвертацию данных
};
