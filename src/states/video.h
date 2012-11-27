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

    bool init();
    void update();
    void close();
    void reset();

    Video() {};
    ~Video() {};

    
};

#endif /* _VIDEO_H_ */

