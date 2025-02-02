#include "pico/stdlib.h"

static const uint RED_SIMULATOR_LED = 11;
static const uint YELLOW_SIMULATOR_LED = 12;
static const uint GREEN_SIMULATOR_LED = 13;

static void led_simulator_init(uint led_pin) {
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
}

void leds_simulator_init() {
    led_simulator_init(RED_SIMULATOR_LED);
    led_simulator_init(YELLOW_SIMULATOR_LED);
    led_simulator_init(GREEN_SIMULATOR_LED);
}

void leds_simulator_status(bool red_status, bool yellow_status, bool green_status) {
    gpio_put(RED_SIMULATOR_LED, red_status);
    gpio_put(YELLOW_SIMULATOR_LED, yellow_status);
    gpio_put(GREEN_SIMULATOR_LED, green_status);
}