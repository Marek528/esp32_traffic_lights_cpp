#pragma once

#include "driver/gpio.h"

class Button
{
  public:
    enum class Connection
    {
        TO_GROUND,
        TO_VCC
    };
    Button(gpio_num_t button_pin, Connection button_conn = Connection::TO_GROUND);

  private:
    gpio_num_t m_button_pin = GPIO_NUM_0;
    Connection m_button_conn = Connection::TO_GROUND;
    static const char *TAG;

  public:
    bool isPressed();
};