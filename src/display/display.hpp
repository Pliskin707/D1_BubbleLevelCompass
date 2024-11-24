#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <Arduino.h>
#include <Adafruit_SSD1351.h>

constexpr uint16_t to_color (const uint8_t r, const uint8_t g, const uint8_t b)
{
  return (static_cast<uint16_t>(r >> 3) << 11) | (static_cast<uint16_t>(g >> 2) << 5) | (b >> 3);
}

// Color definitions
#define	BLACK         to_color(0x00, 0x00, 0x00)  // 0x0000
#define	BLUE          to_color(0x00, 0x00, 0xFF)  // 0x001F
#define	RED           to_color(0xFF, 0x00, 0x00)  // 0xF800
#define	GREEN         to_color(0x00, 0xFF, 0x00)  // 0x07E0
#define CYAN          to_color(0x00, 0xFF, 0xFF)  // 0x07FF
#define MAGENTA       to_color(0xFF, 0x00, 0xFF)  // 0xF81F
#define YELLOW        to_color(0xFF, 0xFF, 0x00)  // 0xFFE0  
#define WHITE         to_color(0xFF, 0xFF, 0xFF)  // 0xFFFF

typedef struct
{
  uint16_t dim    = to_color(24, 0, 0);    // default: very faint red
  uint16_t normal = to_color(48, 0, 0);    // default: slightly brighter red
  uint16_t bright = to_color(255, 0, 0);  // default: maximum brightness red
} color_scheme_t;

typedef struct
{
    int16_t x;
    int16_t y;
} ui_point_t;

class ui_element
{
    protected:
        bool _drawn = false;
        Adafruit_GFX * _display = nullptr;

    public:
        void set_display (Adafruit_GFX * const display) {_display = display;}
        const bool is_drawn (void) {return _drawn;}
        virtual void erase (const uint16_t color = 0) = 0;
};

class ui_compass : public ui_element
{
    private:
        

    public:
        void draw ();   // TODO add parameters
        void erase (const uint16_t color) override;
};

#endif