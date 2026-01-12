#include "Log.hpp"
#include <iostream>

void Log::logToFile(const std::string& message) {
        std::ofstream logFile;

        logFile.open("system_log.txt", std::ios_base::app); 
        if (logFile.is_open()) {
            // Get current time
            time_t result = time(nullptr);
            logFile << ctime(&result) << " - " << message << "\n";
            logFile.close();
        } else {
            std::cerr << "Failed to write to log file." << std::endl;
        }
}