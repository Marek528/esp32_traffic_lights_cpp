#pragma once

#include "driver/gpio.h"
#include "led.h"
#include "button.h"

class Semaphore
{
  public:
    Semaphore(Led red_cars, Led yellow_cars, Led green_cars, Led red_peds, Led green_peds, Led white_peds, Button button);

  private:
    Led m_red_cars;
    Led m_yellow_cars;
    Led m_green_cars;
    Led m_red_peds;
    Led m_green_peds;
    Led m_wait_peds;
    Button m_button;
    static const char *TAG;

  public:
    void state_green_cars();
    void state_green_button_pressed_cars();
    void state_yellow_cars();
    void state_red_cars();
    void state_green_peds();
    void state_red_peds();
    void state_red_yellow_cars();
};