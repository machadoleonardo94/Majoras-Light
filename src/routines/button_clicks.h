#ifndef BUTTON_ROUTINE
#define BUTTON_ROUTINE

#include "shared/dependencies.h"
#include "routines/update_screen.h"
#include "services/wifi_settings.h"

void shutdownESP();
void buttonPress();

void buttonPress()
{
  if (digitalRead(buttonPin))
  {
    idleTimer = 0;
    if (clickCounter > 0)
      buttonTimer++;
    if (buttonState == false)
    {
      clickCounter++;
      buttonState = true;
      delay(10); // debounce
    }
    if ((clickCounter == 4) && (buttonTimer > SAMPLES_TO_SEC))
    {
      connectWiFiScreen();
      setup_WIFI();
      setup_OTA();
    }
  }
  else
  {
    if (buttonState)
    {
      totalHeatingTime += (buttonTimer * SAMPLING_TIMER);
    }
    buttonState = false;
    buttonTimer = 0;
  }
}

#endif