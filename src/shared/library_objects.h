#if !defined(PROJECT_GLOBAL_OBJECTS)
#define PROJECT_GLOBAL_OBJECTS

#include "shared/dependencies.h"
#include "pinout.h"

//* ---------------------- GLOBAL OBJECT INSTANCES ----------------------

//* Fancy LED WS2811
Adafruit_NeoPixel ws2811(NUM_LEDS, LED_output, NEO_RGB + NEO_KHZ800);

#endif // PROJECT_GLOBAL_OBJECTS