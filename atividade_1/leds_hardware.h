#include "pico/stdlib.h"

static const uint GREEN_HARDWARE_LED = 11;
static const uint RED_HARDWARE_LED = 13;

static void led_harware_init(uint led_pin) {
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
}

void leds_hardware_init() {
    led_harware_init(GREEN_HARDWARE_LED);
    led_harware_init(RED_HARDWARE_LED);
}

void leds_hardware_status(bool red_status, bool yellow_status, bool green_status) {    
    gpio_put(RED_HARDWARE_LED, red_status || yellow_status);
    gpio_put(GREEN_HARDWARE_LED, green_status || yellow_status);
}