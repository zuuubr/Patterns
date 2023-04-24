#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <iostream>
#include <vector>
#include <string>

enum figure_id { Square_ID, Triangle_ID, Circle_ID, Rectangle_ID, Oval_ID };

class Figures {
protected:
	int coord;
	std::string color;
	figure_id type;
public:
	virtual void printInfo() = 0;
	virtual void applyToColor(std::string) = 0;
	virtual void applyToCoord(int) = 0;
	virtual void getFormulArea() = 0;
	inline figure_id getType() { return type; }
	static Figures* createFigure(figure_id);
	virtual ~Figures() {};
};

class Square : public Figures {
public:
	Square(figure_id _type) { type = _type; }
	void printInfo() final {
		std::cout << "Figure is: Square" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Coord is: " << coord << std::endl;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}

	void applyToCoord(int _coord) final {
		coord = _coord;
	}

	void getFormulArea() final {
		std::cout << "The area formula for a square is 'a*a'" << std::endl;
	}
	~Square() {};
};

class Triangle : public Figures {
public:
	Triangle(figure_id _type) { type = _type;}
	void printInfo() final {
		std::cout << "Figure is: Triangle" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Coord is: " << coord << std::endl;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}

	void applyToCoord(int _coord) final {
		coord = _coord;
	}

	void getFormulArea() final {
		std::cout << "The area formula for a triangle is '(a * b)/2'" << std::endl;
	}
	~Triangle() {};
};

class Circle : public Figures {
private:
	float radius = 0.0;
public:
	Circle(figure_id _type) { type = _type;}
	virtual void printInfo() final {
		std::cout << "Figure is: Circle" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Coord is: " << coord << std::endl;
		std::cout << "Radius is: " << radius << std::endl;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}

	void applyToCoord(int _coord) final {
		coord = _coord;
	}

	void getFormulArea() final {
		std::cout << "The area formula for a triangle is 'Pi * R * R'" << std::endl;
	}
	~Circle() {};
};


Figures* Figures::createFigure(figure_id ID) {
	Figures* result = NULL;

	switch (ID)
	{
	case Square_ID:
		result = new Square(Square_ID);
		break;
	case Triangle_ID:
		result = new Triangle(Triangle_ID);
		break;
	case Circle_ID:
		result = new Circle(Circle_ID);
		break;
	case Rectangle_ID:
		break;
	case Oval_ID:
		break;
	default:
		exit(1);
	}

	return result;
}

void freeMemmory(std::vector<Figures*> vec) {
	for (int i = 0; i < vec.size(); i++) {
		delete[] vec[i];
	}
}

int main() {
	std::vector<Figures*> vec;

	vec.push_back(Figures::createFigure(Square_ID));
	vec.push_back(Figures::createFigure(Circle_ID));
	vec.push_back(Figures::createFigure(Triangle_ID));
	vec.push_back(Figures::createFigure(Square_ID));
	vec.push_back(Figures::createFigure(Circle_ID));
	vec.push_back(Figures::createFigure(Circle_ID));


	for (int i = 0; i < vec.size(); i++) {
		if (i % 2)
			vec[i]->applyToColor("Red");
		else
			vec[i]->applyToColor("Blue");


		if (vec[i]->getType() == Square_ID) {
			vec[i]->applyToCoord(i);
		}
		else if (vec[i]->getType() == Triangle_ID) {
			vec[i]->applyToCoord(i);
		}
		else if (vec[i]->getType() == Circle_ID) {
			vec[i]->applyToCoord(i);
		}
		else {

		}
	}

	for (int i = 0; i < vec.size(); i++) {
		vec[i]->printInfo();
		vec[i]->getFormulArea();
		std::cout << std::endl;
	}

	freeMemmory(vec);
	_CrtDumpMemoryLeaks();
	return 0;
}

/*
** Назначение паттерна Factory Method
	Система должна оставаться расширяемой путем добавления объектов новых типов. 
	Непосредственное использование выражения new является нежелательным, так как
	в этом случае код создания объектов с указанием конкретных типов может получиться 
	разбросанным по всему приложению. Тогда такие операции как добавление в систему 
	объектов новых типов или замена объектов одного типа на другой будут затруднительными 
	(подробнее в разделе Порождающие паттерны). Паттерн Factory Method позволяет системе 
	оставаться независимой как от самого процесса порождения объектов, так и от их типов.

	Заранее известно, когда нужно создавать объект, но неизвестен его тип.
* 
* 
++ Достоинства паттерна Factory Method
	Создает объекты разных типов, позволяя системе оставаться независимой 
	как от самого процесса создания, так и от типов создаваемых объектов.
-- Недостатки паттерна Factory Method
	В случае классического варианта паттерна даже для порождения единственного 
	объекта необходимо создавать соответствующую фабрику
*
* 
*/
