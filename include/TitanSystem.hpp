#ifndef TITANSYSTEM_HPP
#define TITANSYSTEM_HPP

#include "Sensor.hpp"
#include "Alarm.hpp"
#include <memory>

class TitanSystem  {
    private:
         TitanSystem();
        ~TitanSystem() = default;

        TitanSystem(const TitanSystem& oth) = delete;
        TitanSystem& operator =(const TitanSystem& oth) = delete;   

        std::vector<std::shared_ptr<Sensor>> sensors;

        bool systemArmed;
        std::string currentMode; // "Day", "Night", "Away"

    public:
        static TitanSystem& get_instance();
        
        void addSensor(std::shared_ptr<Sensor> s) { sensors.push_back(s); }
        void removeSensor(const std::string& n);

        void setMode(const std::string& mode);

        void pollSensors(const Alarm& a);

        void generateReport();
};


#endif