#include <iostream>
#include <string>
#include <vector>
#include <map>


enum Figure_ID {square_id, triangle_id, circle_id};

class Figure;
typedef std::map<Figure_ID, Figure*> Registry;

Registry& getResistry() {
	static Registry types;
	return types;
}

class Dumm {};


class Figure {
protected:
	static void addPrototype(Figure_ID type, Figure* prototype) {
		Registry& reg = getResistry();
		reg[type] = prototype;
	}

	static void removePrototype(Figure_ID type) {
		Registry& reg = getResistry();
		reg.erase(reg.find(type));
	}
public:
	virtual Figure* clone() = 0;
	virtual ~Figure() { }
	virtual void printInfo() = 0;
	static Figure* createFigure(Figure_ID type) {
		Registry& reg = getResistry();
		if (reg.find(type) != reg.end()) {
			return reg[type]->clone();
		}
		return 0;
	}
};


class Square : public Figure {
private:
	Square() { }

	Square(Dumm) {
		Figure::addPrototype(square_id, this);
	}
	static Square prototype;

public:
	Figure* clone() final {
		return new Square(*this);
	}

	void printInfo() final {
		std::cout << "Square" << std::endl;
	}
};

class Triangle : public Figure {
private:
	Triangle() { }

	Triangle(Dumm) {
		Figure::addPrototype(triangle_id, this);
	}
	static Triangle prototype;

public:
	Figure* clone() final {
		return new Triangle(*this);
	}
	void printInfo() final {
		std::cout << "Triangle" << std::endl;
	}
};

class Circle : public Figure {
private:
	Circle() { }

	Circle(Dumm) {
		Figure::addPrototype(circle_id, this);
	}
	static Circle prototype;

public:
	Figure* clone() final {
		return new Circle(*this);
	}

	void printInfo() final {
		std::cout << "Circle" << std::endl;
	}
};

Square Square::prototype = Square(Dumm());
Triangle Triangle::prototype = Triangle(Dumm());
Circle Circle::prototype = Circle(Dumm());

int main() {
	std::vector<Figure*> vec;
	vec.push_back(Figure::createFigure(triangle_id));
	vec.push_back(Figure::createFigure(circle_id));
	vec.push_back(Figure::createFigure(square_id));

	for (int i = 0; i < vec.size(); i++) {
		vec[i]->printInfo();
		std::cout << std::endl;
	}

	for (int i = 0; i < vec.size(); i++) {
		delete vec[i];
	}
	return 0;
}

/*
** Назначение паттерна Prototype
	Система должна оставаться независимой как от процесса создания новых 
	объектов, так и от типов порождаемых объектов. Непосредственное использование 
	выражения new в коде приложения считается нежелательным (подробнее об этом в 
	разделе Порождающие паттерны).

	Необходимо создавать объекты, точные классы которых становятся известными уже 
	на стадии выполнения программы.

++	Достоинства паттерна Prototype
	Для создания новых объектов клиенту необязательно знать их конкретные классы.

	Возможность гибкого управления процессом создания новых объектов за счет возможности 
	динамических добавления и удаления прототипов в реестр.

--	Недостатки паттерна Prototype
	Каждый тип создаваемого продукта должен реализовывать операцию клонирования clone(). 
	В случае, если требуется глубокое копирование объекта (объект содержит ссылки или 
	указатели на другие объекты), это может быть непростой задачей.
*/
