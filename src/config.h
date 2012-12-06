//
// config.h
//

#ifndef _CONFIG_H_
#define _CONFIG_H_


#include "singleton.h"
#include <irrlicht.h>


class Config : public Singleton<Config> {
    public:
    
    bool init();
    bool reset();
    void close();

    irr::IrrlichtDevice* getIrrDevice() { return _irrDevice; }

    
    private:

    irr::IrrlichtDevice* _irrDevice;
};


#endif /* _CONFIG_H_ */

