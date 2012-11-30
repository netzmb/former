//
// engine.h
//

#include "singleton.h"

class Engine : public Singleton<Engine> {
    public:
    bool init();
    void loop();
    void close();
};



