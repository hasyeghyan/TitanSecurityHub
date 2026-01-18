#include "MotionSensor.hpp"

void MotionSensor::pollSensor(const Alarm& a) {
    std::cout << "Reading " << getName() << "... ";
    
    if (getData() == 1 && currentMode == "Away") {
        std::cout << "MOTION DETECTED!" << std::endl;
        a.triggerAlarm("Medium", "UserPhone");
    } else {
        std::cout << "No Motion." << std::endl;
    }
}
