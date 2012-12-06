//
// logger.cpp
//

#include <stdarg.h>
#include "logger.h"


#include "config.h"

#define LOG_LINE_BUFSIZE 1024


irr::ILogger* Logger::_irrLogger = NULL;


bool Logger::init() {
    // FIXME get log path from Config, CMake project name as log name
    _irrLogger = (Config::instance().getIrrDevice())->getLogger();

    //Log = &Logger::instance();
    return true;
}


void Logger::close() {
    return;
}


// TODO implement D.R.Y.: aggregate all "va_list" methods to one
//      (use templates or something else)

// TODO move buffer size to private const members

void Logger::info(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	_irrLogger->log(msgBuffer,irr::ELL_INFORMATION);
	return;
}


void Logger::warning(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	_irrLogger->log(msgBuffer,irr::ELL_WARNING);
	return;
}


void Logger::error(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	_irrLogger->log(msgBuffer,irr::ELL_WARNING);
	return;
}


/**
 * accept Irrlicht logging events and write text to
 * specified log file
 *
 */

void Logger::store(const irr::c8* text) {

    return;
}


