/*#include <iostream>

class Singleton {
private:
	Singleton() { };
	Singleton& operator=(Singleton&);
public:
	static Singleton getPointer() {
		static Singleton object;
		return object;
	}
};

int main() {
	Singleton object = Singleton::getPointer();
	std::cout << &object << std::endl;
	return 0;
}*/