/*
*	Basic Polymorphism example
*		Taken from Cplusplus.com
*
*	06/23/15
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Polygon
class Polygon 
{
	protected:
		int width, height;

	public:
		void set_values (int a, int b)
		{ width=a; height=b; }

		/* 
		*  The virtual keyword makes this base classes' 
		*  subclasses polymorphic with the area() because
		*  it is context sensitive.
		*/
		virtual int area()
		{ return 0; }
};

// Rectangle
class Rectangle : public Polygon {
	public: 
		int area()
		{ return width*height; }
};

// Triangle
class Triangle : public Polygon {
	public:
		int area()
		{ return width*height/2; }
};

int main () 
{
	Rectangle rect;
	Triangle trg1;
	Polygon poly;
	Polygon* ppoly1 = &rect;
	Polygon* ppoly2 = &trg1;
	Polygon* ppoly3 = &poly;

	ppoly1->set_values (4, 5); // rect.set_values (4, 5); is equally valid
	ppoly2->set_values (4, 5); // trg1.set_values (4, 5); is equally valid
	ppoly3->set_values (4, 5); // " " " "

	cout << rect.area() << '\n';
	cout << (*ppoly2).area() << '\n';
	cout << ppoly3->area() << '\n';

	return EXIT_SUCCESS;
}