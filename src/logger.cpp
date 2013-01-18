//
// logger.cpp
//

#include "logger.h"
#include "configuration.h"

#include <stdarg.h>
#include <iostream>


#define LOG_LINE_BUFSIZE 1024


irr::ILogger* Logger::_irrLogger = NULL;
irr::io::IWriteFile* Logger::_logFile = NULL;


bool Logger::init() {

	_irrLogger = (Config::instance().getIrrDevice())->getLogger();
	_irrLogger->setLogLevel(irr::ELL_INFORMATION);

    // FIXME get log path from Config, CMake project name as log name
	irr::io::path logPath("former.log");
	irr::io::IFileSystem* fs = Config::instance().getFS();
	_logFile = fs->createAndWriteFile("former.log");

	if (_logFile == NULL)
		warning("Logger::init() failed to open log file: %s", logPath.c_str());

	info("Logger::init() logger initialized");

    setInitialized(true);

    return true;
}


void Logger::close() {
	if (_logFile == NULL)
		return;

	info("Logger::close()");
	_logFile->drop();
    return;
}


// TODO implement D.R.Y.: aggregate all "va_list" methods to one
//      (use templates or something else)

// TODO move buffer size to private constant members

void Logger::info(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	log(msgBuffer, irr::ELL_INFORMATION);
	return;
}


void Logger::warning(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	log(msgBuffer, irr::ELL_WARNING);
	return;
}


void Logger::error(const char* format, ...) {

	char msgBuffer[LOG_LINE_BUFSIZE];

	va_list(argList);

	va_start(argList, format);
	vsprintf(msgBuffer, format, argList);
	va_end(argList);

	log(msgBuffer, irr::ELL_ERROR);
	return;
}


/**
 * accept Irrlicht logging events and write text to
 * specified log file
 *
 */

void Logger::storeLine(const char* text) {

	if (_logFile == NULL)
		return;

	irr::core::stringc logLine(text);
	logLine.append('\n');

	_logFile->write(logLine.c_str(), logLine.size());

	return;
}


void Logger::log(const char* logBuffer, const irr::ELOG_LEVEL logLevel) {

	if (_irrLogger == NULL) {

		switch (logLevel) {
		case irr::ELL_ERROR:
			std::cerr << "ERROR: " << logBuffer << std::endl;
			break;
		default:
			std::cout << logBuffer << std::endl;
			break;
		}

		} else {
		_irrLogger->log(logBuffer, irr::ELL_ERROR);
	}

    return;
}

