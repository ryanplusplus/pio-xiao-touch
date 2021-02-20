#include <Arduino.h>
#include "Adafruit_FreeTouch.h"

extern "C" {
#include <stddef.h>
#include "tiny_digital_output.h"
}

static tiny_digital_output_t led;
static Adafruit_FreeTouch touch = Adafruit_FreeTouch(
  A0,
  OVERSAMPLE_4,
  RESISTOR_0,
  FREQ_MODE_NONE);

void setup()
{
  tiny_digital_output_init(&led, LED_BUILTIN);
  touch.begin();
}

void loop()
{
  tiny_digital_output_write(&led.interface, touch.measure() < 900);
}
