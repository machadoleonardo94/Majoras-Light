#if !defined(START_BREATHING_EFFECT_LEDS)
#define START_BREATHING_EFFECT_LEDS

#define azulNC 0x0, 0x0, 0x50
#define redLED 0xFF, 0x0, 0x0
#define greenLED 0x0, 0xFF, 0x0
#define blueLED 0x0, 0x0, 0xFF

#include "shared/dependencies.h"
#include "shared/pinout.h"
#include <Adafruit_NeoPixel.h>

void blinkLED(int R, int G, int B, int repeat = 3, int waitTime = 1000)
{
    for (int k = 0; k < repeat; k++)
    {
        ws2811.clear();
        ws2811.setPixelColor(0, ws2811.Color(R, G, B)); // it only takes effect if pixels.show() is called
        ws2811.show();                                  // update to the ws2811 Led Strip
        delay(waitTime);
        ws2811.setPixelColor(0, ws2811.Color(0, 0, 0)); // it only takes effect if pixels.show() is called
        ws2811.show();                                  // update to the ws2811 Led Strip
        delay(waitTime);
    }
}

void setLED(int ledNumber, int R, int G, int B)
{
    ws2811.setPixelColor(ledNumber, ws2811.Color(R, G, B)); // it only takes effect if pixels.show() is called
                                                            //    ws2811.setPixelColor(0, ws2811.Color(R, G, B)); // it only takes effect if pixels.show() is called
    ws2811.show();                                          // update to the ws2811 Led Strip
    // delay(waitTime);
    // ws2811.setPixelColor(0, ws2811.Color(0, 0, 0)); // it only takes effect if pixels.show() is called
    // ws2811.show();                                   // update to the ws2811 Led Strip
}

void sampleRandomLED(int first = 0, int last = 10)
{
    uint8_t ledColor = esp_random() % 7 + 1;
    uint ledNumber = esp_random() % (NUM_LEDS);
    // Serial.println(ledColor);
    bool red = ledColor & 1;
    bool green = ledColor & 2;
    bool blue = ledColor & 4;
    if (ledNumber < 10)
        setLED(ledNumber, 25 * red, 25 * green, 25 * blue);
    else if (ledNumber < 26)
        setLED(ledNumber, 250 * red, 250 * green, 250 * blue);
    else if (ledNumber >= 26)
        setLED(ledNumber, 50, 0, 0);
}

#endif // START_BREATHING_EFFECT_LEDS
