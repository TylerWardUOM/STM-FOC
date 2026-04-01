#pragma once

#include "main.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <algorithm>

#ifdef __cplusplus

typedef uint8_t byte;
typedef uint16_t word;
typedef bool boolean;

using std::min;
using std::max;

#define F(x) x

class __FlashStringHelper {};

// must be a complete type if passed by value anywhere
class StringSumHelper {
public:
    const char* c_str() const { return ""; }
};

class Print {
public:
    virtual ~Print() {}
    virtual size_t write(uint8_t) { return 1; }

    void print(const char*) {}
    void print(char) {}
    void print(int) {}
    void print(unsigned int) {}
    void print(long) {}
    void print(unsigned long) {}
    void print(float) {}
    void print(double) {}
    void print(float, unsigned int) {}
    void print(double, unsigned int) {}
    void print(const __FlashStringHelper*) {}
    void print(const StringSumHelper&) {}
    void print(StringSumHelper) {}

    void println() {}
    void println(const char*) {}
    void println(char) {}
    void println(int) {}
    void println(unsigned int) {}
    void println(long) {}
    void println(unsigned long) {}
    void println(float) {}
    void println(double) {}
    void println(float, unsigned int) {}
    void println(double, unsigned int) {}
    void println(const __FlashStringHelper*) {}
    void println(const StringSumHelper&) {}
    void println(StringSumHelper) {}
};

class Stream : public Print {
public:
    int available() { return 0; }
    int read() { return -1; }
    int peek() { return -1; }
};

extern Stream Serial;

extern "C" {
#endif

#define HIGH 1
#define LOW  0

#define OUTPUT 1
#define INPUT  0
#define INPUT_PULLUP 2

#define RISING 1
#define FALLING 2
#define CHANGE 3

#ifndef PI
#define PI 3.14159265358979323846f
#endif

void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
uint32_t millis(void);
uint32_t micros(void);

void pinMode(int pin, int mode);
void digitalWrite(int pin, int state);
int digitalRead(int pin);

#ifdef __cplusplus
}
#endif