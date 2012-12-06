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

    void error(const irr::c8* text) { _irrLogger->log(text, irr::ELL_ERROR); }
    void warning(const irr::c8* text) { _irrLogger->log(text, irr::ELL_WARNING); }
    void info(const irr::c8* text) { _irrLogger->log(text, irr::ELL_INFORMATION); }

    void write(const irr::c8* text);

    Logger& operator()() {
        return instance();
    }

    private:
    irr::ILogger* _irrLogger;
};

#endif /* _LOGGER_H_ */

