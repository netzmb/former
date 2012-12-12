//
// splash_image.h
//

#ifndef _SPLASH_IMAGE_H_
#define _SPLASH_IMAGE_H__

#include "state.h"
#include <irrlicht.h>

using irr::io::path;

class SplashImageState : public State {
public:
	struct Template {
		path imageFile;
		path audioFile;
		irr::u32 timeout;
		Template() : timeout(0){}
	};

	SplashImageState() : _timeout(300), _startTime(0) {};
	~SplashImageState() {};

	bool init();
    void update();
    void close();

    void setImagePath(const char* path) { _imagePath = path; }
    void setAudioPath(const char* path) { _audioPath = path; }
    void setTimeout(irr::u32 timeout) { _timeout = timeout; }

private:
    irr::io::path _imagePath;
    irr::io::path _audioPath;
    irr::u32 _timeout;
    irr::u32 _startTime;
};

#endif /* _SPLASH_IMAGE_H_ */

