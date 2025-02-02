#include <stdlib.h>
#include "leds_simulator.h"
#include "leds_hardware.h"

// o retorno deste método deve ser alterado (true/false) para indicar se é o ambiente é simulado ou real,
// infelizmente não encontrei nenhum mecanismo que determinasse automaticamente.
static bool is_running_on_simulator() {
    return false;
}

void leds_init() {
    printf("%d\n", is_running_on_simulator());
    is_running_on_simulator() ? leds_simulator_init() : leds_hardware_init();
}

void leds_status(bool red_status, bool yellow_status, bool green_status) {
    is_running_on_simulator() ? 
        leds_simulator_status(red_status, yellow_status, green_status) : 
        leds_hardware_status(red_status, yellow_status, green_status);
}