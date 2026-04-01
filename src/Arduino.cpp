#include "Arduino.h"

Stream Serial;

typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
} PinMap;

// Replace this with your real mapping
static PinMap pin_map[] = {
    {GPIOA, GPIO_PIN_0},
    {GPIOA, GPIO_PIN_1},
    {GPIOA, GPIO_PIN_2},
    {GPIOA, GPIO_PIN_3},
    {GPIOA, GPIO_PIN_4},
    {GPIOA, GPIO_PIN_5},
    {GPIOA, GPIO_PIN_6},
    {GPIOA, GPIO_PIN_7},
    {GPIOA, GPIO_PIN_8},
    {GPIOA, GPIO_PIN_9},
    {GPIOA, GPIO_PIN_10},
    {GPIOA, GPIO_PIN_11},
    {GPIOA, GPIO_PIN_12},
    {GPIOA, GPIO_PIN_13},
    {GPIOA, GPIO_PIN_14},
    {GPIOA, GPIO_PIN_15}
};

static inline PinMap getPin(int pin) {
    return pin_map[pin];
}

extern "C" {

void delay(uint32_t ms) {
    HAL_Delay(ms);
}

void delayMicroseconds(uint32_t us) {
    uint32_t start = micros();
    while ((micros() - start) < us) {}
}

uint32_t millis(void) {
    return HAL_GetTick();
}

uint32_t micros(void) {
    return HAL_GetTick() * 1000;
}

void pinMode(int pin, int mode) {
    // leave empty for now; configure in CubeMX
    (void)pin;
    (void)mode;
}

void digitalWrite(int pin, int state) {
    PinMap p = getPin(pin);
    HAL_GPIO_WritePin(p.port, p.pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

int digitalRead(int pin) {
    PinMap p = getPin(pin);
    return HAL_GPIO_ReadPin(p.port, p.pin);
}

}