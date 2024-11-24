#include "sensors.hpp"

void sensors_inertia::setup (void)
{
    Wire.begin();
    _compass.init();
    _compass.enableDefault();

    // TODO calibrate
    _compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
    _compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
}

void sensors_inertia::loop_debug (void)
{
    _compass.read();
    float heading = _compass.heading();
    Serial.println(heading);
}