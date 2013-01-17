//
// statemgr.h
//

#ifndef _STATEMGR_H_
#define _STATEMGR_H_

#include <queue> // STL queue

#include <irrlicht.h>

#include "states/state.h"
#include "singleton.h"
#include "subsystem.h"


class StateManager : public Singleton<StateManager>, public Subsystem {
    public:

	enum StateType {
		STATE_TYPE_SPLASH_IMAGE,
		STATE_TYPE_SPLASH_VIDEO,
		STATE_TYPE_GAMEFLOW,
		STATE_TYPE_COUNT
	};

    
    bool init();
    void update();
    void close();

    State* addState(StateType stateType);
    
    void setDone(bool done) { _isDone = done; };
    bool isDone() const { return _isDone; };

    private:
    //irr::core::list<State*> _states;
    std::queue<State*> _states;
    State* _currentState;
    bool _isDone;
};


#endif /* _STATEMGR_H_ */

