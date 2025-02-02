#include <stdio.h>
#include "pico/stdlib.h"
#include "leds.h"
#include "button.h"
#include "timer.h"

const uint DELAY_MS = 3000;
volatile uint state = 0;

void action() {
    switch (state) {
        case 0:
            state = 3;
            leds_status(true, true, true);
            timer_set_alarm(DELAY_MS, action);   
            break;
        case 1:
            state = 0;
            leds_status(false, false, false);
            break;
        case 2:
            state = 1;
            leds_status(false, false, true);
            timer_set_alarm(DELAY_MS, action);
            break;
        case 3:
            state = 2;
            leds_status(false, true, true);
            timer_set_alarm(DELAY_MS, action);
            break;
    }
}

void on_press() {
    if (state == 0) action();
}

void init() {
    stdio_init_all();
    leds_init();
    button_init(on_press);
}

int main() {
    init();
    while (true) {
        printf("Tempo: %ds\n", (int)(time_us_64()/1000000));
        sleep_ms(1000);
    }
}