//* ---------------------- IMPORTS ----------------------
//* Shared:
#include "shared/dependencies.h"

void shutdownESP();

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(latchPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
  Serial.begin(115200);
  Serial.println("setup");
  workingDisplay = setup_display();
  setup_LEDS();

  setLED(0, redLED);
  setLED(0, greenLED);
  clickCounter = 0;

  setup_ESP32();
  connectWiFiScreen();
  setup_WIFI();
  setup_OTA();
}

void loop()
{
  ArduinoOTA.handle();

  if ((millis() - globalTimer) > SAMPLING_TIMER)
  {
    buttonPress();
    // if (buttonState)
    theaterChaseRainbow(20);
    // theaterChase(ws2811.Color(0, 0, 127), 50);
    //  sampleRandomLED();
    globalTimer = millis();
    idleTimer++;
    logTimer++;
    adcTimer++;
    screenTimer++;
  }

  if (screenTimer > SAMPLES_TO_SEC / 10)
  {
    screenTimer = 0;
    battery = analogReadMilliVolts(1) * 8.2 / 4095;
    updateDisplay();
  }

  if (idleTimer > (SAMPLES_TO_SEC / 2))
  {
    clickCounter = 0;
    // setLED(0, 0, 0);
    // digitalWrite(latchPin, LOW);
    // esp_deep_sleep_start();
  }

  if ((clickCounter > 5) || (idleTimer > (5 * SAMPLES_TO_MIN)))
    shutdownESP();
}

void shutdownESP()
{
  for (int i = 0; i < NUM_LEDS; i++)
    setLED(i, 0, 0, 0);
  delay(50);
  // digitalWrite(latchPin, LOW);
  esp_deep_sleep_start();
}
