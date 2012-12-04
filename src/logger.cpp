//
// logger.h
//

#include "logger.h"

bool Logger::init() {
    // FIXME get log path from Config, CMake project name as log name
    _logFile.open("former-log.txt", std::ios_base::in | std::ios_base::trunc);

    if (!_logFile.is_open()) {
        std::cerr << "Logger::init() can't open log file!" << std::endl;
        return false;
    }

    this->instance() << "Logger initialization()\n";
    return true;
}


void Logger::close() {
    _logFile << "Logger::close()" << std::endl;
    _logFile.close();
    return;
}


