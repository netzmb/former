#include "state.h"


State::State()
 :  _isBatch(true),
    _status(SSTATUS_INIT){
    return;
}


bool State::init() {
    return true;
}


