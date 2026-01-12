#ifndef DOORSENSOR_HPP
#define DOORSENSOR_HPP

#include "Sensor.hpp"

class DoorSensor : public Sensor {
    public:
        DoorSensor(const std::string& n, const std::string& l, int d) : Sensor(n,l,d) {}
        ~DoorSensor() = default;
    
        virtual void pollSensor(const Alarm& a, const std::string& currentMode) override;
};


#endif
