#include "led.h"

#include "esp_log.h"

const char *Led::TAG = "LED";

Led::Led(gpio_num_t led_pin, Connection led_conn)
{
    m_led_pin = led_pin;
    m_led_conn = led_conn;

    gpio_reset_pin(m_led_pin);
    gpio_set_direction(m_led_pin, GPIO_MODE_OUTPUT);

    off();
}

void Led::on()
{
    if (m_led_conn == Connection::TO_GROUND)
    {
        gpio_set_level(m_led_pin, 1);
    }
    else
    {
        gpio_set_level(m_led_pin, 0);
    }
}

void Led::off()
{
    if (m_led_conn == Connection::TO_GROUND)
    {
        gpio_set_level(m_led_pin, 0);
    }
    else
    {
        gpio_set_level(m_led_pin, 1);
    }
}