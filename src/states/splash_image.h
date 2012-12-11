//
// splash_image.h
//

#ifndef _SPLASH_IMAGE_H_
#define _SPLASH_IMAGE_H__

#include "state.h"

class SplashImage : public State {
    bool init();
    void update();
    void close();

private:
    irr::io::path _imagePath;
    irr::u16 _timeout;
};

#endif /* _SPLASH_IMAGE_H_ */

