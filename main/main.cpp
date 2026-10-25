#include <cstdio>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

extern "C" void app_main()
{
    // 1. Конфигурируем пин
    gpio_config_t io_conf = {};

    io_conf.pin_bit_mask = (1ULL << GPIO_NUM_13);  // какой пин
    io_conf.mode = GPIO_MODE_OUTPUT;               // режим: выход
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = (1ULL << GPIO_NUM_27);  // какой пин
    io_conf.mode = GPIO_MODE_OUTPUT;               // режим: выход
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = (1ULL << GPIO_NUM_14);  // какой пин
    io_conf.mode = GPIO_MODE_OUTPUT;               // режим: выход
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);

    // 2. Мигаем
    while (1) {
        gpio_set_level(GPIO_NUM_13, 1);
        vTaskDelay(pdMS_TO_TICKS(5000));
        gpio_set_level(GPIO_NUM_13, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_13, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_27, 1);
        vTaskDelay(pdMS_TO_TICKS(1500));
        gpio_set_level(GPIO_NUM_27, 0);
        gpio_set_level(GPIO_NUM_14, 1);
        vTaskDelay(pdMS_TO_TICKS(7000));
        gpio_set_level(GPIO_NUM_14, 0);
    }
}
