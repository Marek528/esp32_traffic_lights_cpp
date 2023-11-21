#include "button.h"

#include "esp_log.h"

const char *Button::TAG = "BUTTON";

Button::Button(gpio_num_t button_pin, Connection button_conn)
{
    m_button_pin = button_pin;
    m_button_conn = button_conn;

    gpio_reset_pin(m_button_pin);
    gpio_set_direction(m_button_pin, GPIO_MODE_INPUT);
    if (m_button_conn == Connection::TO_GROUND)
    {
        gpio_set_pull_mode(m_button_pin, GPIO_PULLUP_ONLY);
    }
    else
    {
        gpio_set_pull_mode(m_button_pin, GPIO_PULLDOWN_ONLY);
    }
}

bool Button::isPressed()
{
    if (m_button_conn == Connection::TO_GROUND)
    {
        return (gpio_get_level(m_button_pin) == 0);
    }
    else
    {
        return (gpio_get_level(m_button_pin) == 1);
    }
}