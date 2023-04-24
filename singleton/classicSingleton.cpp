#include <iostream>

class Singleton {
private:
	static Singleton* objectPointer;
	Singleton() { };
	Singleton& operator=(Singleton&);
public:
	static Singleton* getPointer() {
		if (!objectPointer) {
			objectPointer = new Singleton;
		}
		return objectPointer;
	}
};


Singleton* Singleton::objectPointer = 0;

int main()
{
	Singleton* ptr;
	ptr = Singleton::getPointer();
	std::cout << ptr << std::endl;
	ptr = Singleton::getPointer();
	std::cout << ptr << std::endl;

	delete ptr;
	return 0;
}

/*
** Назначение паттерна Singleton
	Часто в системе могут существовать сущности только в единственном экземпляре, 
	например, система ведения системного журнала сообщений или драйвер дисплея. В таких 
	случаях необходимо уметь создавать единственный экземпляр некоторого типа, 
	предоставлять к нему доступ извне и запрещать создание нескольких экземпляров того же типа.
* 
*
++ Достоинства паттерна Singleton
	Класс сам контролирует процесс создания единственного экземпляра.
	Паттерн легко адаптировать для создания нужного числа экземпляров.
	Возможность создания объектов классов, производных от Singleton.
-- Недостатки паттерна Singleton
	В случае использования нескольких взаимозависимых одиночек их реализация 
	может резко усложниться.
* 
* 
*/
