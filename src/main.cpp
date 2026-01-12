#include <stdexcept>
#include "TitanSystem.hpp"
#include "DoorSensor.hpp"
#include "MotionSensor.hpp"
#include "HeatSensor.hpp"
#include "Log.hpp"

int main() {
    try {
        std::shared_ptr<Sensor> doorSensor= std::make_shared<DoorSensor>("Door Sensor", "Entry", 0);
        std::shared_ptr<Sensor> heatSensor= std::make_shared<HeatSensor>("Heat Sensor", "Kitchen", 25);
        std::shared_ptr<Sensor> motionSensor= std::make_shared<MotionSensor>("Motion Sensor", "Living Room", 0);


        TitanSystem homeSecurity;
        homeSecurity.addSensor(doorSensor);
        homeSecurity.addSensor(heatSensor);
        homeSecurity.addSensor(motionSensor);


        std::cout << "--- Titan Security System v1.0 ---\n";


        homeSecurity.setMode("Away");
  
        std::shared_ptr<IDS> ids = std::make_shared<Log>();
        Alarm alarm(ids);

        // 3. Simulate "Normal" Check
        homeSecurity.pollSensors(alarm);

        // 4. Intruder scenario!
        std::cout << "\n[SIMULATION] Intruder breaks open the front door...\n";
        doorSensor->simulateSensorInput(1); // set to 1 (Open)
        
        homeSecurity.pollSensors(alarm);

        // 5. Fire scenario!
        std::cout << "\n[SIMULATION] Kitchen catches fire...\n";
        heatSensor->simulateSensorInput(60); // Index 2 is Heat, set to 60C
        
        homeSecurity.pollSensors(alarm);

    } catch (const std::exception& e) {
        std::cout << "CRITICAL ERROR: " << e.what() << std::endl;
    }

    return 0;
}