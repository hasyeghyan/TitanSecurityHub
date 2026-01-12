#ifndef IDS_HPP
#define IDS_HPP
#include <string>

class IDS {
    public:
        virtual void logToFile(const std::string& s) = 0;
};


#endif