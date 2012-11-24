#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T> class SingletonClass {

	public:

		static T &instance() {
			static T SingletonInstance;
			return SingletonInstance;
        }

        static T &operation() {}

	private:

		SingletonClass();
		~SingletonClass();
		SingletonClass(SingletonClass const &Object);
		SingletonClass &operator=(SingletonClass const &Object);
};

#endif
