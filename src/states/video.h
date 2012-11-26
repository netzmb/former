//
// video.h
//
// state for processing video 
//


#ifndef _VIDEO_H_
#define _VIDEO_H_

#include "state.h"

class Video : public State {
    public:

    Video() {};
    ~Video() {};
    bool init();
    void update();
    void close();
    void reset();
};

#endif /* _VIDEO_H_ */

