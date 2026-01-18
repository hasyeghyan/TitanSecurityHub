#ifndef MOTIONSENSOR_HPP
#define MOTIONSENSOR_HPP

#include "Sensor.hpp"

class MotionSensor : public Sensor {
    public:
        MotionSensor(const std::string& n, const std::string& l, int d, const std::string& c) : Sensor(n,l,d,c) {}
        ~MotionSensor() = default;

        void pollSensor(const Alarm& a) override;
};


#endif