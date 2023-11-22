#include "semaphore.h"
#include "button.h"
#include "led.h"

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

const char *Semaphore::TAG = "SEMAPHORE";

const TickType_t TIME_WAITING = 5000;
const TickType_t TIME_YELLOW_CARS = 2000;
const TickType_t TIME_CARS_TRANSIT = 2000;
const TickType_t TIME_GREEN_PEDS = 5000;
const TickType_t TIME_PEDS_TRANSIT = 5000;
const TickType_t TIME_RED_YELLOW = 1000;

Semaphore::Semaphore(Led red_cars, Led yellow_cars, Led green_cars, Led red_peds, Led green_peds, Led wait_peds, Button button)
  : m_red_cars(red_cars),
    m_yellow_cars(yellow_cars),
    m_green_cars(green_cars),
    m_red_peds(red_peds),
    m_green_peds(green_peds),
    m_wait_peds(wait_peds),
    m_button(button)
{}

void Semaphore::state_green_cars()
{
    m_red_cars.off();
    m_yellow_cars.off();
    m_green_cars.on();
    m_red_peds.on();
    m_green_peds.off();
    m_wait_peds.off();

    while (!m_button.isPressed())
    {
        vTaskDelay(1);
    }
}

void Semaphore::state_green_button_pressed_cars()
{
    m_wait_peds.on();

    vTaskDelay(TIME_WAITING / portTICK_PERIOD_MS);
}

void Semaphore::state_yellow_cars()
{
    m_yellow_cars.on();
    m_green_cars.off();

    vTaskDelay(TIME_YELLOW_CARS / portTICK_PERIOD_MS);
}

void Semaphore::state_red_cars()
{
    m_red_cars.on();
    m_yellow_cars.off();

    vTaskDelay(TIME_CARS_TRANSIT / portTICK_PERIOD_MS);
}

void Semaphore::state_green_peds()
{
    m_red_peds.off();
    m_green_peds.on();
    m_wait_peds.off();

    vTaskDelay(TIME_GREEN_PEDS / portTICK_PERIOD_MS);
}

void Semaphore::state_red_peds()
{
    m_red_peds.on();
    m_green_peds.off();

    vTaskDelay(TIME_PEDS_TRANSIT / portTICK_PERIOD_MS);
}

void Semaphore::state_red_yellow_cars()
{
    m_yellow_cars.on();

    vTaskDelay(TIME_RED_YELLOW / portTICK_PERIOD_MS);
}