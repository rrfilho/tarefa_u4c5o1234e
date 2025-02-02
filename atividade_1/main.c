#include <stdio.h>
#include "pico/stdlib.h"
#include "leds.h"
#include "timer.h"

const uint INTERVAL_MS = 3000;
uint state = 0;

void next_state() {
    switch (state) {
        case 0: leds_status(true, false, false); break;
        case 1: leds_status(false, true, false); break;
        case 2: leds_status(false, false, true); break;
    }
    state = ++state%3;
}

void init() {
    stdio_init_all();
    leds_init();
    timer_init(INTERVAL_MS, next_state);
}

int main() {
    init();
    while (true) {
        printf("Tempo: %ds\n", (int)(time_us_64()/1000000));
        sleep_ms(1000);
    }
}
