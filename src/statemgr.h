//
// statemgr.h
//



#ifndef _STATEMGR_H_
#define _STATEMGR_H_

#include <list>
#include "state.h"
#include "singleton.h"

class StateManager {
    public:
    bool init();
    void update();
    void close();

    private:
    std::list<State> _states;
    
};

typedef SingletonClass<StateManager> StateMgr;

#endif /* _STATEMGR_H_ */

