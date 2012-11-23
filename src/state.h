//
// statemgr.cpp
//



#ifndef _STATE_H_
#define _STATE_H_

class State {
    public:
    enum StateStatus {
       SSTATUS_INIT,
       SSTATUS_EXECUTING,
       SSTATUS_PAUSE,
       SSTATUS_DONE
    };

    bool isBatch() const { return _isBatch; };

    private:

    bool _isBatch;

};


#endif /* _STATE_H_ */
