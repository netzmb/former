//
// config.h
//

#ifndef _CONFIG_H_
#define _CONFIG_H_


#include "singleton.h"


class Config : public Singleton<Config> {
    public:
    
    bool init() { reset(); return true; };
    void reset() {};
    void close() {};

    
    private:

    
};


#endif /* _CONFIG_H_ */

