//
// singleton.h
//

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <class T>

class Singleton {
    public:

    static T& instance() {
        static T *_instance;

        if (_instance == 0)
            _instance = new T;

        return *_instance;
    }
};

#endif /* _SINGLETON_H_ */

