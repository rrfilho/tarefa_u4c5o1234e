#include "pico/stdlib.h"

const uint LEFT_BUTTON = 5;
const uint DEBOUNCE_TIME_LIMIT_US = 200000;

typedef void (*handler)();

static handler _handler;
static volatile uint left_button_last_time_us = 0;

static uint now_us() {
    return to_us_since_boot(get_absolute_time());
}

static bool has_wait_time_reached(uint last_time) {
    return now_us() - last_time >= DEBOUNCE_TIME_LIMIT_US;
}

static void handler_adapter_with_debounce(uint gpio, uint32_t event_mask) {
    if (!has_wait_time_reached(left_button_last_time_us)) return;
    _handler();
    left_button_last_time_us = now_us();
}

void button_init(handler handler) {
    _handler = handler;
    gpio_init(LEFT_BUTTON);
    gpio_set_dir(LEFT_BUTTON, GPIO_IN);
    gpio_pull_up(LEFT_BUTTON);
    gpio_set_irq_enabled_with_callback(LEFT_BUTTON, GPIO_IRQ_EDGE_FALL, true, handler_adapter_with_debounce);
}