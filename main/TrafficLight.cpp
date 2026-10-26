#include "TrafficLight.hpp"

TrafficLight::TrafficLight(gpio_num_t green, gpio_num_t yellow, gpio_num_t red) : green_(green), yellow_(yellow), red_(red){}

void TrafficLight::init(){
    gpio_config_t gconf = {};
    gconf.pin_bit_mask = (1ULL << green_);
    gconf.mode = GPIO_MODE_OUTPUT;
    gconf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gconf.pull_up_en = GPIO_PULLUP_DISABLE;
    gconf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&gconf);

    gconf.pin_bit_mask = (1ULL << yellow_);
    gpio_config(&gconf);

    gconf.pin_bit_mask = (1ULL << red_);
    gpio_config(&gconf);
}

void TrafficLight::turnonGreen(){
        gpio_set_level(green_, 1);
        vTaskDelay(pdMS_TO_TICKS(5000));
        gpio_set_level(green_, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(green_, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
}

void TrafficLight::turnonYellow(){
    gpio_set_level(yellow_, 1);
    vTaskDelay(pdMS_TO_TICKS(1500));
    gpio_set_level(yellow_, 0);
}

void TrafficLight::turnonRed(){
    gpio_set_level(red_, 1);
    vTaskDelay(pdMS_TO_TICKS(7000));
    gpio_set_level(red_, 0);
}

void TrafficLight::runCycle(){
    turnonGreen();
    turnonYellow();
    turnonRed();
}