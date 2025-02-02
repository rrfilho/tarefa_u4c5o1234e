#include "pico/stdlib.h"
#include "hardware/timer.h"

typedef void (*handler)();

static struct repeating_timer timer;
static handler timer_handler;

static int64_t handler_adapter(alarm_id_t id, void *user_data) {
    timer_handler();
    return 0;
}

void timer_set_alarm(uint delay, handler handler) {
    timer_handler = handler;
    add_alarm_in_ms(delay, handler_adapter, NULL, false);
}

