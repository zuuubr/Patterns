#include <iostream>
#include <vector>
#include <string>


enum type_id {square_id, triangle_id, circle_id};
enum desk_id {desk_one_id, desk_two_id};

// Перечисление всех возможных видов фигур (без перечесиления принадлежности и количества)
class Square {
protected:
	desk_id desk;
	type_id type;
	std::string color;
public:
	Square() { type = square_id; }
	virtual void printInfo() = 0;
	virtual void applyToDesk() = 0;
	virtual void applyToColor(std::string) = 0;
	virtual ~Square() {};
};

class Triangle {
protected:
	desk_id desk;
	type_id type;
	std::string color;
public:
	Triangle() { type = triangle_id; }
	virtual void printInfo() = 0;
	virtual void applyToDesk() = 0;
	virtual void applyToColor(std::string) = 0;
	virtual ~Triangle() {};
};

class Circle {
protected:
	desk_id desk;
	type_id type;
	std::string color;
public:
	Circle() { type = circle_id; }
	virtual void printInfo() = 0;
	virtual void applyToDesk() = 0;
	virtual void applyToColor(std::string) = 0;
	virtual ~Circle() {};
};


// Переопределяем классы, добавляем свойства для каждой фигуры 1 доски
class DeskOneSquare : public Square {
public:
	void printInfo() final {
		std::cout << "the object belongs to the FIRST BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_one_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};

class DeskOneTriangle : public Triangle {
public:
	void printInfo() final {
		std::cout << "the object belongs to the FIRST BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_one_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};

class DeskOneCircle : public Circle {
public:
	void printInfo() final {
		std::cout << "the object belongs to the FIRST BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_one_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};


// Переопределяем классы, добавляем свойства для каждой фигуры 2 доски
class DeskTwoSquare : public Square {
public:
	void printInfo() final {
		std::cout << "the object belongs to the SECOND BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_two_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};

class DeskTwoTiangle : public Triangle {
public:
	void printInfo() final {
		std::cout << "the object belongs to the SECOND BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_two_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};

class DeskTwoCircle : public Circle {
public:
	void printInfo() final {
		std::cout << "the object belongs to the SECOND BOARD" << std::endl;
		std::cout << "Color is: " << color << std::endl;
		std::cout << "Type is: " << type << std::endl;
		std::cout << "Desk is: " << desk << std::endl;
	}

	void applyToDesk() final {
		desk = desk_two_id;
	}

	void applyToColor(std::string _color) final {
		color = _color;
	}
};


// Абстрактная фабрика создания фигур
class AbstractFactory {
public:
	virtual Square* createSquare() = 0;
	virtual Triangle* createTriangle() = 0;
	virtual Circle* createCircle() = 0;
	virtual ~AbstractFactory() {};
};

// Класс для создания фигур 1 доски
class DeskOneFactory : public AbstractFactory {
public:
	Square* createSquare() {
		return new DeskOneSquare;
	}
	
	Triangle* createTriangle() {
		return new DeskOneTriangle;
	}

	Circle* createCircle() {
		return new DeskOneCircle;
	}
};

// Класс для создания фигур 2 доски
class DeskTwoFactory : public AbstractFactory {
public:
	Square* createSquare() {
		return new DeskTwoSquare;
	}

	Triangle* createTriangle() {
		return new DeskTwoTiangle;
	}

	Circle* createCircle() {
		return new DeskTwoCircle;
	}
};


// Класс содержащий объекты всех типов фигур одной доски
class Geometry {
public:
	std::vector<Square*> vectorSquare;
	std::vector<Triangle*> vectorTriangle;
	std::vector<Circle*> vectorCircle;

	void printInfo() {
		for (int i = 0; i < vectorSquare.size(); i++) vectorSquare[i]->printInfo();
		for (int i = 0; i < vectorTriangle.size(); i++) vectorTriangle[i]->printInfo();
		for (int i = 0; i < vectorCircle.size(); i++) vectorCircle[i]->printInfo();
	}

	void applyToDesk() {
		for (int i = 0; i < vectorSquare.size(); i++) vectorSquare[i]->applyToDesk();
		for (int i = 0; i < vectorTriangle.size(); i++) vectorTriangle[i]->applyToDesk();
		for (int i = 0; i < vectorCircle.size(); i++) vectorCircle[i]->applyToDesk();
	}

	void applyToColor(std::string _color) {
		for (int i = 0; i < vectorSquare.size(); i++) vectorSquare[i]->applyToColor(_color);
		for (int i = 0; i < vectorTriangle.size(); i++) vectorTriangle[i]->applyToColor(_color);
		for (int i = 0; i < vectorCircle.size(); i++) vectorCircle[i]->applyToColor(_color);
	}

	~Geometry() {
		for (int i = 0; i < vectorSquare.size(); i++) delete[] vectorSquare[i];
		for (int i = 0; i < vectorTriangle.size(); i++) delete[] vectorTriangle[i];
		for (int i = 0; i < vectorCircle.size(); i++) delete[] vectorCircle[i];
	}
};


// Класс для управления, объединяющий создание всех объектов 
class Windows {
public:
	Geometry* createFigures(AbstractFactory& factory) {
		Geometry* result = new Geometry;

		result->vectorSquare.push_back(factory.createSquare());
		result->vectorTriangle.push_back(factory.createTriangle());
		result->vectorCircle.push_back(factory.createCircle());

		return result;
	}
};

int main() {
	Windows window;
	DeskOneFactory dof;
	DeskTwoFactory dtf;
	Geometry* deskOneFigure = window.createFigures(dof);
	Geometry* deskTwoFigure = window.createFigures(dtf);

	deskOneFigure->applyToColor("RED");
	deskOneFigure->applyToDesk();

	deskTwoFigure->applyToColor("BLUE");
	deskTwoFigure->applyToDesk();

	deskOneFigure->printInfo();
	deskTwoFigure->printInfo();


	delete deskOneFigure;
	delete deskTwoFigure;

	return 0;
}


/*
** Назначение паттерна Abstract Factory
	Система должна оставаться независимой как от процесса создания новых объектов, 
	так и от типов порождаемых объектов. Непосредственное использование выражения 
	new в коде приложения нежелательно (подробнее об этом в разделе Порождающие паттерны).

	Необходимо создавать группы или семейства взаимосвязанных объектов, исключая 
	возможность одновременного использования объектов из разных семейств в одном контексте.
* 
* 
++ Достоинства паттерна Abstract Factory
	Скрывает сам процесс порождения объектов, а также делает систему 
	независимой от типов создаваемых объектов, специфичных для различных 
	семейств или групп (пользователи оперируют этими объектами через 
	соответствующие абстрактные интерфейсы).
	Позволяет быстро настраивать систему на нужное семейство создаваемых объектов. 
	В случае многоплатформенного графического приложения для перехода на новую платформу, 
	то есть для замены графических элементов (кнопок, меню, полос прокрутки) одного стиля 
	другим достаточно создать нужный подкласс абстрактной фабрики. При этом условие 
	невозможности одновременного использования элементов разных стилей для некоторой 
	платформы будет выполнено автоматически.
-- Недостатки паттерна Abstract Factory
	Трудно добавлять новые типы создаваемых продуктов или заменять существующие, так как 
	интерфейс базового класса абстрактной фабрики фиксирован. Например, если для нашей 
	стратегической игры нужно будет ввести новый вид военной единицы - осадные орудия, 
	то надо будет добавить новый фабричный метод, объявив его интерфейс в полиморфном 
	базовом классе AbstractFactory и реализовав во всех подклассах. Снять это ограничение 
	можно следующим образом. Все создаваемые объекты должны наследовать от общего абстрактного 
	базового класса, а в единственный фабричный метод в качестве параметра необходимо передавать 
	идентификатор типа объекта, который нужно создать. Однако в этом случае необходимо учитывать 
	следующий момент. Фабричный метод создает объект запрошенного подкласса, но при этом 
	возвращает его с интерфейсом общего абстрактного класса в виде ссылки или указателя, поэтому 
	для такого объекта будет затруднительно выполнить какую-либо операцию, специфичную для подкласса.
*
* 
*/
