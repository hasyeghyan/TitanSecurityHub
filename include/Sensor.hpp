#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Alarm.hpp"

class Sensor {
    private: 
        std::string name;
        std::string location;
        int data;

        std::string currentMode;
    public:
        Sensor(const std::string& n, const std::string& l, int d) : name{n}, location{l}, data{d} {}
        virtual ~Sensor() {}

        const std::string& getName() const noexcept { return name; }
        int getData() const noexcept { return data; }

        void getInfo(); 

        virtual void pollSensor(const Alarm& a, const std::string& currentMode) = 0;
        
        void simulateSensorInput(int value) { data = value; }
};


#endif