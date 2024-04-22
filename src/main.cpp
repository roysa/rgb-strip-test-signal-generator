#include <Arduino.h>
#include <FastLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/Picopixel.h>

#include "pinconfig.h"

#define DEFAULT_PROGRAM 0
#define DEFAULT_R 128
#define DEFAULT_G 128
#define DEFAULT_B 128

typedef enum {
  SINGLE,
  ALL,
} Programs;


typedef enum {
  NONE,
  SET_PROGRAM,
  SET_R,
  SET_G,
  SET_B,
} ControlMode;

CRGB leds[NUM_LEDS];

#ifdef DISPLAY_I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#endif

#ifdef DISPLAY_SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  DIS_MOSI_PIN, DIS_SCK_PIN, DIS_DC_PIN, DIS_RESET_PIN, DIS_CS_PIN);
#endif

ControlMode controlMode = NONE;
Programs program = ALL;


uint8_t colorR = 1;
uint8_t colorG = 24;
uint8_t colorB = 14;

void updateLeds()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(colorR, colorG, colorB);
    if (program == SINGLE && i != 0)
    {
      leds[i] = CRGB::Black;
    }
  }

  FastLED.show();
}

void switchModeNext()
{
  controlMode = (ControlMode)((controlMode + 1) % 5);
}

void switchProgram(Programs programIndex)
{

  

}

void updateDisplay()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  if (controlMode == SET_PROGRAM) {
    display.print(">");
  } else {
    display.print(" ");
  }
  display.print("Program: ");
  display.println(program == SINGLE ? "Single" : "All");

  if (controlMode == SET_R) {
    display.print(">");
  } else {
    display.print(" ");
  }
  display.print("R ");
  display.println(colorR);

  if (controlMode == SET_G) {
    display.print(">");
  } else {
    display.print(" ");
  }
  display.print("G ");
  display.println(colorG);

  if (controlMode == SET_B) {
    display.print(">");
  } else {
    display.print(" ");
  }
  display.print("B ");
  display.println(colorB);
  display.display();
}

void onEncoderRotate(int increment)
{
  switch (controlMode)
  {
  case SET_PROGRAM:
    program = (Programs)((program + increment) % 2);
    break;
  case SET_R:
    colorR = (colorR + increment) % 256;
    break;
  case SET_G:
    colorG = (colorG + increment) % 256;
    break;
  case SET_B:
    colorB = (colorB + increment) % 256;
    break;
  default:
    break;
  }
}

unsigned long modeLastChanged = 0;
int prevClk = HIGH;

void setup() {

  pinMode(ENC_CLK_PIN, INPUT);
  pinMode(ENC_DT_PIN, INPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  
  FastLED.addLeds<NEOPIXEL, LED_DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(128);

  #ifdef DISPLAY_I2C
  display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_I2C_ADDRESS);
  #endif
  #ifdef DISPLAY_SPI
  display.begin(SSD1306_SWITCHCAPVCC);
  #endif

  delay(1000);

  switchProgram(ALL);
  updateDisplay();
  updateLeds();

}

void loop() {

  if (digitalRead(BTN_PIN) == LOW && millis() - modeLastChanged > 300) {
    modeLastChanged = millis();
    switchModeNext();
    updateDisplay();
  }

  int clk = digitalRead(ENC_CLK_PIN);
  if (clk != prevClk && clk == LOW) {
    int dt = digitalRead(ENC_DT_PIN);
    int delta = dt == HIGH ? 1 : -1;
    onEncoderRotate(delta);
    updateDisplay();
    updateLeds();
  }
  prevClk = clk;

}
