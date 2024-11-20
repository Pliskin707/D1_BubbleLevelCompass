#include <Arduino.h>
#include <ESP8266WiFi.h>

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128

// You can use any (4 or) 5 pins 
#define SCLK_PIN D5
#define MOSI_PIN D7
#define DC_PIN   D2
#define CS_PIN   D8
#define RST_PIN  D1

// Color definitions
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// Option 2: must use the hardware SPI pins 
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be 
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN, DC_PIN, RST_PIN);

void setup() {
  WiFi.mode(WIFI_OFF);
  pinMode(LED_BUILTIN, OUTPUT);
  tft.begin();
  delay(500);
  tft.fillScreen(BLACK);
}

void loop() {
  delay(500);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  tft.drawLine(0, 0, 20, tft.height()-1, RED);
}