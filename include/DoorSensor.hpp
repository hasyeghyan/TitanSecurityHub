#ifndef DOORSENSOR_HPP
#define DOORSENSOR_HPP

#include "Sensor.hpp"

class DoorSensor : public Sensor {
    public:
        DoorSensor(const std::string& n, const std::string& l, int d, const std::string& c) : Sensor(n,l,d,c) {}
        ~DoorSensor() = default;
    
        virtual void pollSensor(const Alarm& a) override;
};


#endif
