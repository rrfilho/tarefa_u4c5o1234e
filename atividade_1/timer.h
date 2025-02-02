#include "pico/stdlib.h"
#include "hardware/timer.h"

typedef void (*handler)();

static struct repeating_timer timer;
static handler timer_handler;

static bool handler_adapter(repeating_timer_t *t) {
    timer_handler();
    return true;
}

void timer_init(uint interval_ms, handler handler) {
    timer_handler = handler;
    add_repeating_timer_ms(interval_ms, handler_adapter, NULL, &timer);
}

