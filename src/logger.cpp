//
// logger.cpp
//

#include "logger.h"

#include "config.h"

bool Logger::init() {
    // FIXME get log path from Config, CMake project name as log name
    irr::IrrlichtDevice* device = Config::instance().getIrrDevice();
    irr::ILogger* tmp_logger = device->getLogger();
    _irrLogger = (Config::instance().getIrrDevice())->getLogger();
    return true;
}


void Logger::close() {
    return;
}


void Logger::write(const irr::c8* text) {

    return;
}


