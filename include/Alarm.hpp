#ifndef ALARM_HPP
#define ALARM_HPP

#include <iostream>
#include <string>
#include "IDS.hpp"
#include <memory>

class Alarm {
    private:
        std::shared_ptr<IDS> ids;
    public:
        Alarm(std::shared_ptr<IDS> i) : ids{i} {}
        
        void triggerAlarm(const std::string& severity, const std::string& notifyWho) const;
};

#endif