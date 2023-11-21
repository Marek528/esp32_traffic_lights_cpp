#include "driver/gpio.h"
#include "esp_log.h"

#include "led.h"
#include "button.h"
#include "semaphore.h"

static const char *TAG = "MAIN";

const gpio_num_t GPIO_LED_RED_CARS_PIN = GPIO_NUM_2;
const gpio_num_t GPIO_LED_YELLOW_CARS_PIN = GPIO_NUM_4;
const gpio_num_t GPIO_LED_GREEN_CARS_PIN = GPIO_NUM_5;
const gpio_num_t GPIO_LED_RED_PEDS_PIN = GPIO_NUM_12;
const gpio_num_t GPIO_LED_GREEN_PEDS_PIN = GPIO_NUM_13;
const gpio_num_t GPIO_LED_BUTTON_PRESSED = GPIO_NUM_14;
const gpio_num_t GPIO_BUTTON = GPIO_NUM_18;

extern "C"
{
    void app_main(void)
    {
        ESP_LOGI(TAG, "Start of main");
        Led redCars(GPIO_LED_RED_CARS_PIN);
        Led yellowCars(GPIO_LED_YELLOW_CARS_PIN);
        Led greenCars(GPIO_LED_GREEN_CARS_PIN);
        Led redPeds(GPIO_LED_RED_PEDS_PIN);
        Led greenPeds(GPIO_LED_GREEN_PEDS_PIN);
        Led waitPeds(GPIO_LED_BUTTON_PRESSED);
        Button waitbutton(GPIO_BUTTON);
        Semaphore trafficLight(redCars, yellowCars, greenCars, redPeds, greenPeds, waitPeds, waitbutton);

        while (true)
        {
            trafficLight.state_green_cars();
            trafficLight.state_green_button_pressed_cars();
            trafficLight.state_yellow_cars();
            trafficLight.state_red_cars();
            trafficLight.state_green_peds();
            trafficLight.state_red_peds();
            trafficLight.state_red_yellow_cars();
        }
    }
}
