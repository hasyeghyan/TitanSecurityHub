#ifndef LOG_HPP
#define LOG_HPP

#include "IDS.hpp"
#include <fstream>
#include <ctime>

class Log : public IDS {
    void logToFile(const std::string& message);
};

#endif