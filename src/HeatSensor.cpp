#include "HeatSensor.hpp"

void HeatSensor::pollSensor(const Alarm& a, const std::string& currentMode) {
    std::cout << "Reading " << getName() << "... Temp: " << getData() << "C. ";
    
    if (getData() > 50) {
        std::cout << "DANGER! FIRE!" << std::endl;
            a.triggerAlarm("Critical", "FireDept");
    } else {
        std::cout << "Normal." << std::endl;
    }
}