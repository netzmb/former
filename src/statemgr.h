//
// statemgr.h
//



#ifndef _STATEMGR_H_
#define _STATEMGR_H_

#include <list>
#include "state.h"


class StateMgr {
    public:
    void update();

    private:
    std::list<State> _states;
    
};


#endif /* _STATEMGR_H_ */

