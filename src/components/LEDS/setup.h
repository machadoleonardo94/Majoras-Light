#if !defined(SETUP_LEDS)
#define SETUP_LEDS

#include "shared/dependencies.h"
#include "components/LEDS/features/WS_functions.h"

void setup_LEDS()
{
    Serial.println("[LEDS] SETUP STARTED!");

    ws2811.begin();
    ws2811.clear();
    ws2811.setBrightness(250); // Set BRIGHTNESS to about 1/5 (max = 255)
    /*
    ws2811.setPixelColor(0, ws2811.Color(50, 0, 0)); // it only takes effect if pixels.show() is called
    ws2811.show();                                    // update to the ws2811 Led Strip
    delay(500);
    ws2811.setPixelColor(0, ws2811.Color(0, 50, 0)); // it only takes effect if pixels.show() is called
    ws2811.show();                                    // update to the ws2811 Led Strip
    delay(500);
    ws2811.setPixelColor(0, ws2811.Color(0, 0, 50)); // it only takes effect if pixels.show() is called
    ws2811.show();                                    // update to the ws2811 Led Strip
    delay(500);
    // ws2811.setPixelColor(0, ws2811.Color(0, 0, 0)); // it only takes effect if pixels.show() is called
    // ws2811.show();
    */
    Serial.println("[LEDS] SETUP FINISHED!");
}

#endif // SETUP_LEDS
