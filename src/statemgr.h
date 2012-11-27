//
// statemgr.h
//



#ifndef _STATEMGR_H_
#define _STATEMGR_H_

#include <list>
#include "states/state.h"
#include "singleton.h"

class StateManager {
    public:
    bool init();
    void update();
    void close();

    void add(State* state);
    
    void setDone(bool done) { _isDone = done; };
    bool isDone() const { return _isDone; };

    private:
    //std::list<State> _states;
    std::list<State*> _states;
    bool _isDone;
};

typedef SingletonClass<StateManager> StateMgr;

#endif /* _STATEMGR_H_ */

