#include "./display.hpp"

void ui_compass::erase (const uint16_t color)
{
    if (!is_drawn())
        return;

    // TODO

    _drawn = false;
}

void ui_compass::draw ()
{
    ui_element::erase();

    // TODO
}