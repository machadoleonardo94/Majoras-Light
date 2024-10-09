#include "shared/dependencies.h"

void theaterChaseRainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void theaterChaseRainbow(uint8_t wait)
{
    if (pixelInterval != wait)
        pixelInterval = wait; //  Update delay time
    for (int i = 0; i < (NUM_LEDS); i += 3)
    {
        ws2811.setPixelColor(i + pixelQueue, Wheel((i + pixelCycle) % 255)); //  Update delay time
    }
    ws2811.show();
    for (int i = 0; i < (NUM_LEDS); i += 3)
    {
        ; // ws2811.setPixelColor(i + pixelQueue, ws2811.Color(0, 0, 0)); //  Update delay time
    }
    pixelQueue++; //  Advance current queue
    pixelCycle++; //  Advance current cycle
    if (pixelQueue >= 3)
        pixelQueue = 0; //  Loop
    if (pixelCycle >= 256)
        pixelCycle = 0; //  Loop
}

uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return ws2811.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        return ws2811.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return ws2811.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait)
{
    static uint32_t loop_count = 0;
    static uint16_t current_pixel = 0;

    pixelInterval = wait; //  Update delay time

    ws2811.clear();

    for (int c = current_pixel; c < NUM_LEDS; c += 3)
    {
        ws2811.setPixelColor(c, color);
    }
    ws2811.show();

    current_pixel++;
    if (current_pixel >= 3)
    {
        current_pixel = 0;
        loop_count++;
    }

    if (loop_count >= 10)
    {
        current_pixel = 0;
        loop_count = 0;
        patternComplete = true;
    }
}
