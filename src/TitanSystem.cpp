#include "TitanSystem.hpp"

TitanSystem::TitanSystem() { 
    systemArmed = false; 
    currentMode = "Day";
}

TitanSystem& TitanSystem::get_instance() {
    static TitanSystem ts;
    return ts;
}

void TitanSystem::removeSensor(const std::string& n) {
    for (size_t i{}; i < sensors.size(); ++i) {
        if (sensors[i]->getName() == n) {
            sensors.erase(sensors.begin() + i);
            --i;
        }
    }
}

 void TitanSystem::setMode(const std::string& mode) {
    if (mode == "Day" || mode == "Night" || mode == "Away") {
        currentMode = mode;
        std::cout << "[System] Mode set to: " << mode << std::endl;
        if (mode == "Away") {
            systemArmed = true;
        }
    } else {
        std::cout << "[Error] Unknown mode." << std::endl;
    }
}

void TitanSystem::pollSensors(const Alarm& a) {
    if (systemArmed) {
        for (size_t i{}; i < sensors.size(); ++i) {
            sensors[i]->pollSensor(a);
        }
    }
}

void TitanSystem::generateReport() {
    std::cout << "\nGenerating System Report..." << std::endl;
    std::cout << "Sensors Online: " << sensors.size() << std::endl;
    std::cout << "System Armed: " << (systemArmed ? "YES" : "NO") << std::endl;
}
