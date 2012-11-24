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

    State();

    bool isBatch() const { return _isBatch; };

    bool init();
    void update();
    void close();
    void change(StateStatus status) { _status = status; };

    StateStatus getStatus() const {return _status;}; 

    private:

    bool _isBatch;
    StateStatus _status;
};


#endif /* _STATE_H_ */
