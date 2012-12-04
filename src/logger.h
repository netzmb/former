//
// logger.h
//

#ifndef _LOGGER_H_
#define _LOGGER_H_


#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::ofstream
#include <sstream>  // std::ostringstream

#include <irrlicht.h>
#include "singleton.h"


class Logger : public Singleton<Logger> {
    public:
    
    bool init();
    void close();

    void operator<<(const char* msg) {

        // TODO implement D.R.Y.
        std::ostringstream _out;
        _out << "Logger: " << msg;
        _logFile << _out.str();
        std::cout << _out.str();
        return;
    }

    void operator<<(const irr::core::vector3df& vector) {
        
        std::ostringstream _out;
        _out << "(" << vector.X
             << "," << vector.Y
             << "," << vector.Z << ")";

        this->instance() << _out.str().c_str();
        
        return;
    }

    Logger& operator()() {
        return instance();
    }

    private:

    std::ofstream _logFile;
};

#endif /* _LOGGER_H_ */

