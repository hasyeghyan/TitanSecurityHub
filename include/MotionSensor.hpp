#ifndef MOTIONSENSOR_HPP
#define MOTIONSENSOR_HPP

#include "Sensor.hpp"

class MotionSensor : public Sensor {
    public:
        MotionSensor(const std::string& n, const std::string& l, int d) : Sensor(n,l,d) {}
        ~MotionSensor() = default;

        void pollSensor(const Alarm& a, const std::string& currentMode) override;
};


#endif