#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_GPIO 4

static const char *TAG = "PROJECT_X";

void configurer_led(void) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    ESP_LOGI(TAG, "Broche GPIO %d configuree en sortie.", LED_GPIO);
}

void app_main(void) {
    ESP_LOGI(TAG, "Démarrage du programme avec LED extérieure...");
    configurer_led();

    while (1) {
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}