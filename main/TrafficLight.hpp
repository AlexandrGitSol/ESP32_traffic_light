#pragma once
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class TrafficLight{
public:
    TrafficLight(gpio_num_t green, gpio_num_t yellow, gpio_num_t red);
    void init();
    void turnonGreen();
    void turnonYellow();
    void turnonRed();
    void runCycle();

private:
    gpio_num_t green_, yellow_, red_;

};