//
//
//


#ifndef _SINGLETON2_H_
#define _SINGLETON2_H_


#include <list>


class Singleton {
    public:
    
    //static void create(const char * name, Singleton * single);
    //static Singleton* instance();
    //static Singleton* instance();
    
    virtual bool init();
    
    static Singleton &instance() {
        //static Singleton _instance;
        return _instance;
        }

    
    protected:
    //static Singleton * lookup(const char * name);
    //Singleton() {};
    
    
    private:
		Singleton() {};
		virtual ~Singleton() {};
		Singleton(Singleton const &Object) {};
		virtual Singleton &operator=(Singleton const &Object);

    //static Singleton* _instance;
    //static std::list<>
    
    static Singleton _instance;
    
};


#endif /* _SINGLETON2_H_ */
