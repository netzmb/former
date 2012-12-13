//
// splash_image.h
//

#ifndef _SPLASH_IMAGE_H_
#define _SPLASH_IMAGE_H__

#include "state.h"
#include <irrlicht.h>

using irr::io::path;
using irr::video::SColor;

class SplashImageState : public State {
public:

	SplashImageState();
	~SplashImageState() {};

	bool init();
    void update();
    void close();

    void setImagePath(const char* path) { _imagePath = path; }
    void setAudioPath(const char* path) { _audioPath = path; }
    void setTimeout(irr::u32 timeout) { _timeout = timeout; }
    void setBackColor(SColor color) { _backColor = color; }

private:
    irr::io::path _imagePath;
    irr::io::path _audioPath;
    irr::u32 _timeout;
    SColor _backColor;

    irr::video::ITexture* _splashTexture;
    irr::u32 _startTime;
    SColor _oldFrameColor;
};

#endif /* _SPLASH_IMAGE_H_ */

