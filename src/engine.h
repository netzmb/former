//
// engine.h
//


#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "singleton.h"

class Engine : public Singleton<Engine> {
    public:
    bool init(int argc, char **argv);
    void loop();
    void close();

    bool isDone() const { return _isDone; }

    private:
    static void sysSignalHandler(int sig_num=0);

    void initSubSystem(bool initSuccess);
    bool _isDone;
};

#endif /* _ENGINE_H_ */

