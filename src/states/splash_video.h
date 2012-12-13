//
// splash_video.h
//

#include "state.h"
#include <irrlicht.h>

using irr::video::SColor;

class SplashVideoState : public State {
public:
	SplashVideoState(){};
	~SplashVideoState(){};

	bool init();
    void update();
    void close();

    void setVideoPath(const char* path) { _videoPath = path; }
    void setBackColor(SColor color) { _backColor = color; }

private:
    irr::io::path _videoPath;
    SColor _backColor;
    SColor _oldFrameColor;
};
