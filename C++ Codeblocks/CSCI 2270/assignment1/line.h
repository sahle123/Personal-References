#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

/*
 * line.h
 * For assignment 1 for CSCI 2270
 *
 *  Created on: 02-18-12
 *      Author: Sahle A. Alturaigi
 *
 *
 */

#include"point.h"
using namespace std;

class line {
private:
	point p1;  // (x1, y1)
	point p2;  // (x2, y2)

public:
	// Constructors
	line();                                 // Constructor initializes to zero.
	line(point);                         // Constructor initializes the line to be passing through (0, 0) and a programmer provided point object.
	line(point, point);               // Constructor initializes the line to be passing through two programmer-provided point objects.
	line(const line &cSource)   // Copy Constructor
	{
		p1 = cSource.p1;
		p2 = cSource.p2;
	}

	// Modification Functions
	double get_x1() {return p1.get_x();}
	double get_x2() {return p2.get_x();}
	double get_y1() {return p1.get_y();}
	double get_y2() {return p2.get_y();}

	double slope();
	void translate(double, double);
	void reflect_x();
	void reflect_y();

	// Overloaded Operands
	friend istream& operator >> (istream& ins, line& target);
	friend ostream& operator << (ostream& outs, line& target);
	friend bool  operator == (line &obj_1, line &obj_2);
	line& operator = (const line &obj);

protected:
     double find_b(line& equation) const;
};

line::line() {
	p1.set_x(0);
	p1.set_y(0);

	p2.set_x(0);
	p2.set_y(0);
}

line::line(point node_1) {
	p1.set_x(node_1.get_x());
	p1.set_y(node_1.get_y());

	p2.set_x(0);
	p2.set_y(0);

}

line::line(point node_1, point node_2) {
	p1.set_x(node_1.get_x());
	p1.set_y(node_1.get_y());

	p2.set_x(node_2.get_x());
	p2.set_y(node_2.get_y());
}

double line::slope() {
	if(p1.get_x() == p2.get_x())
	{
		return 0.0;
	}
	else
	{
		return (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
	}

}

void line::translate(double X, double Y) {
	p1.set_x(p1.get_x() + X);
	p1.set_y(p1.get_y() + Y);

	p2.set_x(p2.get_x() + X);
	p2.set_y(p2.get_y() + Y);
}

void line::reflect_x() {
	p1.set_x(-p1.get_x());
	p2.set_x(-p2.get_x());
}

void line::reflect_y() {
	p1.set_y(-p1.get_y());
	p2.set_y(-p2.get_y());
}

// Overloaded "==" operator.
bool operator == (line& obj_1, line& obj_2) {
	return (obj_1.p1.get_x() == obj_2.p1.get_x())
			&&
			(obj_1.p1.get_y() == obj_2.p1.get_y())
			&&
			(obj_1.p2.get_x() == obj_2.p2.get_x())
			&&
			(obj_1.p2.get_y() == obj_2.p2.get_y());

}

// Overloaded "=" operator.
line& line::operator = (const line &obj) {

	if(this != &obj)
	{
		p1 = obj.p1;
		p2 = obj.p2;
	}
	return *this;
}

// Overloaded ">>" operator.
istream& operator >> (istream& ins, line& target)
{
     int x1, x2;
     int y1, y2;
     ins >> x1 >> y1 >> x2 >> y2;

     target.p1.set_x(x1);
     target.p1.set_y(y1);
     target.p2.set_x(x2);
     target.p2.set_y(y2);

     return ins;

}

// Overloaded "<<" operator.
ostream& operator << (ostream& outs, line& target)
{
     outs << target.get_x1() << ","<< target.get_y1() << ","<< target.get_x2()
     << ","<< target.get_y2() << endl;

     outs << "y = mx + b" << endl;
     outs << "m = " << target.slope() << endl;
     outs <<  "y = "<< target.slope() << "x"<< " + " << target.find_b(target)
     << endl;

     return outs;
}

double line::find_b(line& equation) const
{
     double b;
     b = (equation.get_y1()) - (equation.slope()*equation.get_x1());
     return b;
}

#endif // LINE_H_INCLUDED
