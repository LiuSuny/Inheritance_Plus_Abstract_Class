#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <io.h>
#include <algorithm>
#include <vector>




using namespace std;

enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}

//Описать абстрактный класс ФИГУРА.
//Поля:
//цвет
//координаты левой верхней точки
//высота
//ширина


//методы :
//показать фигуру - чисто виртуальный метод
//вернуть площадь - чисто виртальный метод
//вернуть периметр - чисто виртуальный метод
//set - методы для всех полей
//get - методы для всех полей
//перемещение фигуры

//Описать набор классов наследников :
//Прямоугольник
//Равнобедренный треугольник
//Прямоугольный треугольник

//В main создать вектор указателей на все существующие типы фигур.
//Осуществить возможность работы с любым объектом.
//Добавление / удаление фигуры в массив.

//Describe the abstract class FIGURE.
//Fields:
//color
//coordinates of the upper left point
//height
//width

class Figure
{
protected:
	Color color;
	size_t X, Y;
	int height;
	int width;

	//methods :
public:
	//show shape - pure virtual method
	virtual void showShape() = 0; //abstract func ->pure virtual
	//return area - pure virtual method
	virtual int getArea() = 0;
	//return perimeter - pure virtual method
	virtual int getParameter() = 0;
	//set - methods for all fields
		 //void setcolor(Color color, int height, int width, )
	void setcolor(Color color_t)
	{
		color = color_t;
	}
	void setX(size_t x_coord)
	{
		X = x_coord;
	}
	void setY(size_t y_coord)
	{
		Y = y_coord;
	}
	void setHeight(int hgt)
	{
		if (hgt >= 0 && hgt <= 99)
		{
			height = hgt;
		}
	}
	void setWidth(int wdt)
	{
		if (wdt >= 0 && wdt <= 99)
		{
			width = wdt;
		}
	}
	//get - methods to get all our fields
	Color getColor() const
	{
		return color;
	}
	size_t getX() const
	{
		return X;
	}
	size_t getY()const
	{
		return Y;
	}
	int getHeight()const
	{
		return height;
	}
	int getWidth() const
	{
		return width;
	}
	// method for movement of our shape
	void moveShape(size_t X_move, size_t Y_move)
	{
		X += X_move;
		Y += Y_move;
	}
};

//Describe a set of descendant classes:
//Rectangle
class Rect_angle : public Figure
{
public:
	Rect_angle() : Rect_angle(0, 0, 2, 2, Green)
	{
		cout << "ctor with out args\n";
	}
	Rect_angle(const size_t X, const size_t Y) : Rect_angle(X, Y, 2, 2, Blue)
	{
		cout << "ctor with coordinate\n";
		this->X = X;
		this->Y = Y;
	}
	Rect_angle(const size_t X, const size_t Y, const int hgt, const int wdt, const Color color)
	{
		this->color = color;
		this->X = X;
		this->Y = Y;
		this->height = hgt;
		this->width = wdt;

	}
	void showShape()override
	{
		setColor(color, Magenta);
		setCursor(X, Y);
		for (size_t i = 0; i < height; i++)
		{
			setCursor(X, Y + i);

			for (size_t j = 0; j < width; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		setColor(White, Black);

	}
	int getArea()override
	{
		return height * width;
	}
	int getParameter()override
	{
		return 2 * (height + width);
	}

};
//Isosceles triangle
class Isosceles_triangle : public Figure
{
public:
	Isosceles_triangle() : Isosceles_triangle(0, 0, 2, 2, Green)
	{
		cout << "ctor Isosceles_triangle with out args\n";
	}
	Isosceles_triangle(const size_t X, const size_t Y) :Isosceles_triangle(X, Y, 2, 2, Blue)
	{
		cout << "ctor with coordinate Isosceles_triangle\n";
		this->X = X;
		this->Y = Y;
	}
	Isosceles_triangle(const size_t X, const size_t Y, const int hgt, const int wdt, const Color color)
	{
		this->color = color;
		this->X = X;
		this->Y = Y;
		this->height = hgt;
		this->width = wdt;

	}
	void showShape()override
	{

		setCursor(X, Y);
		for (size_t i = 0; i <= height / 2; i++)
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < width; j++)
			{
				if (j < height / 2 - i || j> width / 2 + i)
				{
					setColor(Black, Black);
				}
				else
				{
					setColor(Color(color), Color(color));
				}
				cout << "*";
			}
		}
		setColor(color, Black);
		cout << endl;
	}

	int getArea() override
	{
		return 0.5 * width * height;
	}
	int getParameter() override
	{
		size_t side = sqrt(pow(width / 2, 2) + pow(height, 2));
		return 2 * side + width;
	}

};
//Right triangle треугольник прямоугольный
class treygonik : public Figure
{
public:
	treygonik() : treygonik(0, 0, 2, 2, Green)
	{
		cout << "ctor right_triangle with out args\n";
	}
	treygonik(const size_t X, const size_t Y) :treygonik(X, Y, 2, 2, Blue)
	{
		cout << "ctor with coordinate right_triangle\n";
		this->X = X;
		this->Y = Y;
	}
	treygonik(const size_t X, const size_t Y, const int hgt, const int wdt, const Color color)
	{
		this->color = color;
		this->X = X;
		this->Y = Y;
		this->height = hgt;
		this->width = wdt;

	}
	void showShape()override
	{
		setCursor(X, Y);
		setColor(Cyan, Black);
		for (int i = 1; i <= height; i++)
		{
			setCursor(X, Y + i);
			for (int j = i; j <= width; j++)
			{
				cout << "* ";
			}
			cout << endl;

		}
		setColor(White, Black);
		cout << endl;
	}

	int getArea() override
	{
		return 0.5 * width * height;
	}
	int getParameter() override
	{
		size_t hypotenuse = sqrt(pow(width, 2) + pow(height, 2));
		return height + width + hypotenuse;
	}

};




void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));



	vector <Figure*> figures; // вектор указателей на фигур.

	//Создаем объекты разных типов фигур и добавляем их в вектор
	figures.push_back(new  Rect_angle(5, 5, 15, 15, Red));
	figures.push_back(new Isosceles_triangle(10, 10, 20, 20, Cyan));
	figures.push_back(new treygonik(20, 20, 30, 30, Blue));

	/*int index;
	cout << "Enter the figure you want to see?";
	cin >> index;
	figures[index]->showShape();*/
	// Вывод информации о фигурах и их характеристиках
	for (Figure* var : figures)
	{
		var->showShape();

		cout << "Area: " << var->getArea() << endl;
		cout << "Parameter: " << var->getParameter() << endl;
	}
	cout << endl;

	//removing a figure to the array.
	for (Figure* var : figures)
	{
		delete[]var;
	}





}



