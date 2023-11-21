#pragma once

#include "driver/gpio.h"

class Led
{
  public:
    enum class Connection
    {
        TO_GROUND,
        TO_VCC
    };
    Led(gpio_num_t led_pin, Connection led_conn = Connection::TO_GROUND);

  private:
    gpio_num_t m_led_pin = GPIO_NUM_0;
    Connection m_led_conn = Connection::TO_GROUND;
    static const char *TAG;

  public:
    void off();
    void on();
};