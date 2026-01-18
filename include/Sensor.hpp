#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Alarm.hpp"

class Sensor {
    protected: 
        std::string name;
        std::string location;
        int data;

        std::string currentMode;
    public:
        Sensor(const std::string& n, const std::string& l, int d, const std::string& c) : name{n}, location{l}, data{d}, currentMode{c} {}
        virtual ~Sensor() {}

        const std::string& getName() const noexcept { return name; }
        int getData() const noexcept { return data; }

        void getInfo(); 

        virtual void pollSensor(const Alarm& a) = 0;
        
        void simulateSensorInput(int value) { data = value; }
};


#endif