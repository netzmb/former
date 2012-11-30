//
// singleton.h
//

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template <class T>

class Singleton {
    public:

    static T &instance() {
        static T *_instance;

        if (_instance == 0)
            _instance = new T;

        return *_instance;
    }

//    protected:
//    Singleton();

    private:
};

/*
 * examples
 *

class Graphics : public Singleton<Graphics> {
    public:

    enum Side {
        SIDE_NONE,
        SIDE_TOP,
        SIDE_BOTTOM
        };

    bool init() { _side = SIDE_NONE; return true;};

    void setSide(Side side) { _side = side; } ;
    void putSide() const  {std::cout << (int)_side << std::endl;} ;


    private:

    int _side;


};


class Audio : public Singleton<Audio> {
    public:
    void putSide() const  {std::cout << "audio" << std::endl;} ;

};



int main() {

//    Graphics::instance().testSide(GraphicsClass::SIDE_TOP);
    Graphics::instance();
    Graphics::instance();
    Graphics::instance().init();
    Graphics::instance().putSide();
    Graphics::instance().setSide(Graphics::SIDE_BOTTOM);
    Graphics::instance().putSide();
    Graphics::instance().setSide(Graphics::SIDE_TOP);
    Graphics::instance().putSide();
    Graphics::instance();

    Audio::instance().putSide();
    Graphics::instance().putSide();
    Audio::instance().putSide();
    Graphics::instance().putSide();

    return 0;
}

*/


#endif /* _SINGLETON_H_ */

