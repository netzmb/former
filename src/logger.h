//
// logger.h
//

#ifndef _LOGGER_H_
#define _LOGGER_H_


#include <irrlicht.h>
#include "singleton.h"
#include "subsystem.h"




class Logger : public Singleton<Logger>, public Subsystem {
    public:

    bool init();
    void close();

    static void error(const char* format, ...);
    static void warning(const char* format, ...);
    static void info(const char* format, ...);

    static void storeLine(const char* text);

    

    private:

    static void log(const char* logBuffer, const irr::ELOG_LEVEL logLevel);

    static irr::ILogger* _irrLogger;
    static irr::io::IWriteFile* _logFile;
};

#endif /* _LOGGER_H_ */

