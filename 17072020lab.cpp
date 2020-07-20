Лабораторная работа №21
Курс : Объектно - ориентированное программирование на C++
Встреча №21
Тема : АбсТракТНый класс и вирТуальНый десТрукТор
Задания для самостоятельной работы :
Задание №1
Создать абстрактный базовый класс Employer(служащий) с чисто виртуальной функцией Print().Создайте три производных класса : President, Manager, Worker.Переопределите функцию Print() для вывода информации, соответствующей каждому типу служащего.

/*
Задание №1
Создать абстрактный базовый класс Employer (служащий) с чисто виртуальной функцией Print().
Создайте три производных класса: President, Manager, Worker.
Переопределите функцию Print() для вывода информации, соответствующей каждому типу служащего.
*/
#include <iostream>
using namespace std;
class Employer {
	char* PIB;
	int AGE;
	double SALARY;
public:
	Employer(const char* pib, int age, double salary) {
		PIB = _strdup(pib);
		AGE = age;
		SALARY = salary;
	}
	virtual void Print() = 0 {
		cout << "PIB: " << PIB << endl;
		cout << "Age: " << AGE << endl;
		cout << "Salary: " << SALARY << endl;
	}
	virtual	~Employer() {
		delete[]PIB;
		cout << "Delete Employer" << endl;
	}
};

class President : public Employer {
	char* COUNTRY;
	char* BDAY;
public:
	President(const char* pib, int age, double salary, const char* country, const char* bday) :Employer(pib, age, salary) {
		COUNTRY = _strdup(country);
		BDAY = _strdup(bday);
	}
	void Print() {
		Employer::Print();
		cout << "COUNTRY : " << COUNTRY << endl;
		cout << "BDAY : " << BDAY << endl;
	}
	~President() {
		delete[]COUNTRY;
		delete[]BDAY;
		cout << "Delete President" << endl;
	}
};

class Manager : public Employer {
	char* FIRMA;
public:
	Manager(const char* pib, int age, double salary, const char* country, const char* bday, char* firma) :Employer(pib, age, salary) {
		FIRMA = _strdup(firma);
	}
	void Print() {
		Employer::Print();
		cout << "FIRMA : " << FIRMA << endl;
	}
	~Manager() {
		delete[]FIRMA;
		cout << "Delete Manager" << endl;
	}
};

class Worker : public Employer {
	char* JOB;
public:
	Worker(const char* pib, int age, double salary, const char* country, const char* bday, char* firma, char* job) :Employer(pib, age, salary) {
		JOB = _strdup(firma);
	}
	void Print() {
		Employer::Print();
		cout << "JOB : " << JOB << endl;
	}
	~Worker() {
		delete[]JOB;
		cout << "Delete Worker" << endl;
	}
};

int main()
{
	//Employer B("asda", 2, 3);
	President A("Tramp", 68, 10000.25, "USA", "01.01.1952");
	A.Print();
	cout << "The End!\n";
}
Задание №2
Создать абстрактный базовый класс с виртуальной функцией – площадь.Создать производные классы : прямоугольник, круг, прямоугольный треугольник, трапеция со своими функциями площади.Для проверки определить массив ссылок на абстрактный класс, которым присваиваются адреса различных объектов.

/*
Задание №2
Создать абстрактный базовый класс с виртуальной функцией – площадь.
Создать производные классы: прямоугольник, круг, прямоугольный треугольник, трапеция со своими функциями площади.
Для проверки определить массив ссылок на абстрактный класс, которым присваиваются адреса различных объектов.
Create an abstract base class with a virtual function - area.
Create derived classes: rectangle, circle, right triangle, trapezoid with its area functions.
To check, define an array of links to an abstract class, which are assigned the addresses of various objects.
*/
#include <iostream>
#include <time.h>
using namespace std;

class BaseClass {
public:
	virtual double Area() = 0;
	virtual void Show() = 0;
	virtual ~BaseClass() {}
};

class Rectangle :public BaseClass {
	double A;
	double B;
public:
	Rectangle(double a, double b) : A(a), B(b) { }
	~Rectangle() {}
	double Area() { return A * B; }
	void Show() { cout << "Rectangle Area = " << Area() << endl; }
};

class Circle : public BaseClass
{
	double C;
public:
	Circle(double c) : C(c) {}
	~Circle() {}
	double Area() { return 3.14 * C * C; }
	void Show() { cout << "Circle Area = " << Area() << endl; }
};

class RightTriangle : public BaseClass
{
	double D;
	double E;
public:
	RightTriangle(double d, double e) : D(d), E(e) { }
	~RightTriangle() {}
	double Area() { return (D * E) / 2; }
	void Show() { cout << "Right Triangle Area = " << Area() << endl; }
};

class Trapezoid : public BaseClass
{
	double F;
	double G;
	double H;
public:
	Trapezoid(double f, double g, double h) : F(f), G(g), H(h) { }
	~Trapezoid() {}
	double Area() { return (F + G) / 2 * H; }
	void Show() { cout << "Trapezoid Area = " << Area() << endl; }
};

void foo(int n) {
	BaseClass** arr = new BaseClass * [n];
	for (size_t i = 0; i < n; i++)
	{
		int R = rand() % 4;
		if (R == 0) arr[i] = new Rectangle(2, 3);
		if (R == 1) arr[i] = new Circle(2);
		if (R == 2) arr[i] = new RightTriangle(2, 3);
		if (R == 3) arr[i] = new Trapezoid(2, 3, 4);
	}
	for (size_t i = 0; i < n; i++)
	{
		arr[i]->Show();
	}
}

int main() {
	Rectangle A(2, 3);
	A.Show();
	Circle B(2);
	B.Show();
	RightTriangle C(2, 3);
	C.Show();
	Trapezoid D(2, 3, 4);
	D.Show();
	cout << "***********foo(4) : " << endl;
	foo(4);
}
