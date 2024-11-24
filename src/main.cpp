#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "./display/display.hpp"
#include "./sensors/sensors.hpp"

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128
#define DARK_MODE

// You can use any (4 or) 5 pins 
#define SPI_SCLK_PIN  D5
#define SPI_MOSI_PIN  D7
#define SPI_DC_PIN    D4
#define SPI_CS_PIN    D8
// #define SPI_RST_PIN   D1

#define I2C_SDA       D2
#define I2C_SCL       D1

// Option 2: must use the hardware SPI pins 
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be 
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
static Adafruit_SSD1351 oled = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, SPI_CS_PIN, SPI_DC_PIN);
static color_scheme_t color_scheme;
static sensors_inertia sensors;

void setup() {
  WiFi.mode(WIFI_OFF);
  pinMode(LED_BUILTIN, OUTPUT);
  oled.begin();
  delay(500);
  oled.fillScreen(BLACK);

  Serial.begin(115200);
  Serial.print(F("Hello World!"));
  sensors.setup();

  #ifndef DARK_MODE
  color_scheme = 
  {
    .dim    = to_color(40, 40, 40),
    .normal = to_color(120, 120, 120),
    .bright = to_color(255, 200, 200)
  };
  #endif
}

void loop() {
  static uint_fast16_t counter = 0;
  delay(500);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  oled.drawRect(0, 0, oled.width() - 1, oled.height() - 1, color_scheme.dim);
  oled.drawCircle(oled.width() / 2, oled.height() / 2, (oled.width() / 2) - 4, color_scheme.normal);
  oled.setCursor(oled.width() / 2, oled.height() / 2);
  oled.setTextColor(color_scheme.bright, BLACK);
  oled.printf_P(PSTR("Test %u"), counter++);

  sensors.loop_debug();
}