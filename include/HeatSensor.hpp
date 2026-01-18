#ifndef HEATSENSOR_HPP
#define HEATSENSOR_HPP

#include "Sensor.hpp"

class HeatSensor : public Sensor {
    public:
        HeatSensor(const std::string& n, const std::string& l, int d, const std::string& c) : Sensor(n,l,d,c) {}
        ~HeatSensor() = default;
       
        void pollSensor(const Alarm& a) override;
};


#endif