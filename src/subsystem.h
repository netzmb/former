//
// subsystem.h
//

#ifndef _SUBSYSTEM_H_
#define _SUBSYSTEM_H_

#include <iostream>

class Subsystem {
    public:
    Subsystem() : _initialized(false) {};
    bool isInitialized() const { return _initialized; };
    void setInitialized(bool initialized) { _initialized = initialized; };
    // FIXME added only for testing
    private:
    bool _initialized;
};

#endif
