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
    irr::io::IFileSystem* getFS() { return _irrDevice->getFileSystem(); }
    irr::u32 getTime() {return _irrTimer->getTime();}
    
    private:

    irr::IrrlichtDevice* _irrDevice;
    irr::ITimer* _irrTimer;
};

#endif /* _CONFIG_H_ */
