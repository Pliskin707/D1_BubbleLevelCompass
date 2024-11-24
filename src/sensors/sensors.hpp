#ifndef __SENSORS_HPP__
#define __SENSORS_HPP__

#include <Wire.h>
#include <LSM303.h>

class sensors_inertia
{
    private:
        LSM303 _compass;

    public:
        void setup (void);
        void loop_debug (void);

};

#endif