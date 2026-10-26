#include <cstdio>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "TrafficLight.hpp"

extern "C" void app_main()
{
    TrafficLight tl(GPIO_NUM_13, GPIO_NUM_27, GPIO_NUM_14);
    tl.init();
    while(true) tl.runCycle();
}
