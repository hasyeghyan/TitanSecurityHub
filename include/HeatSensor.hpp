#ifndef HEATSENSOR_HPP
#define HEATSENSOR_HPP

#include "Sensor.hpp"

class HeatSensor : public Sensor {
    public:
        HeatSensor(const std::string& n, const std::string& l, int d) : Sensor(n,l,d) {}
        ~HeatSensor() = default;
       
        void pollSensor(const Alarm& a, const std::string& currentMode) override;
};


#endif