#include "DoorSensor.hpp"

void DoorSensor::pollSensor(const Alarm& a) {
    std::cout << "Reading " << getName() << "... ";
    
    if (getData()) {
        std::cout << "OPEN! Triggering Alarm!" << std::endl;
        a.triggerAlarm("High", "Police");
    } else {
        std::cout << "Secure." << std::endl;
    }
} 
