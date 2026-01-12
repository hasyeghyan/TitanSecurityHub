#include "DoorSensor.hpp"

void DoorSensor::pollSensor(const Alarm& a, const std::string& currentMode) {
    std::cout << "Reading " << getName() << "... ";
    
    if (getData() == 1) {
        std::cout << "OPEN! Triggering Alarm!" << std::endl;
        a.triggerAlarm("High", "Police");
    } else {
        std::cout << "Secure." << std::endl;
    }
} 
