#pragma once

#include "AP_HAL_SITL.h"

class HALSITL::GPIO : public AP_HAL::GPIO {
public:
    explicit GPIO(SITL_State *sitlState): _sitlState(sitlState) {}
    void init();
    void pinMode(uint8_t pin, uint8_t output);
    uint8_t read(uint8_t pin);
    void write(uint8_t pin, uint8_t value);
    void toggle(uint8_t pin);

    /* Alternative interface: */
    AP_HAL::DigitalSource* channel(uint16_t n);

    /* return true if USB cable is connected */
    bool usb_connected(void);

private:
    SITL_State *_sitlState;
};

class HALSITL::DigitalSource : public AP_HAL::DigitalSource {
public:
    explicit DigitalSource(uint8_t pin);
    void mode(uint8_t output);
    uint8_t read();
    void write(uint8_t value);
    void toggle();

private:
    uint8_t _pin;
};
