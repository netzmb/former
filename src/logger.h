//
// logger.h
//

#ifndef _LOGGER_H_
#define _LOGGER_H_


#include <irrlicht.h>
#include "singleton.h"




class Logger : public Singleton<Logger> {
    public:

    bool init();
    void close();

    //static void error(const char* text) { _irrLogger->log(text, irr::ELL_ERROR); }
    static void error(const char* format, ...);
    //static void warning(const char* text) { _irrLogger->log(text, irr::ELL_WARNING); }
    static void warning(const char* format, ...);
    //static void info(const char* text) { _irrLogger->log(text, irr::ELL_INFORMATION); }
    static void info(const char* format, ...);

    //static void format(const char* format, ...);

    static void store(const char* text);

    private:
    static irr::ILogger* _irrLogger;
};

#endif /* _LOGGER_H_ */

