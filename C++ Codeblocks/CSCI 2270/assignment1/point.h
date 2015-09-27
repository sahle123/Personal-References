#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

/*
 * point.h
 * For assignment 1 for CSCI 2270
 *
 *  Created on: 02-18-12
 *      Author: Sahle A. Alturaigi
 *
 *      COMPILES AND WORKS FULL WELL. THIS LIBRARY MAY BE USED.
 *
 */

#include<math.h>
#include<iostream>
using namespace std;

class point {
private:
	double x_point, y_point;

public:
	// Constructors
	point();                                  // Initializes to 0,0. Default.
	point(double, double);          // Takes user inputs. Other.
	point(const point &cSource) // Copy constructor.
	{
		x_point = cSource.x_point;
		y_point = cSource.y_point;
	}

	// Modification Functions
	double get_x() {return x_point;} // Gets x value.
	double get_y() {return y_point;} // Gets y value.
	void set_x(double x){x_point = x;} // Set x's value.
	void set_y(double y){y_point = y;} // Sets y's value.
	void translate(double X, double Y); // Translates the point X and Y many points.
	void scale(double m); // Increases the amplitude of the line.
	void reflect_x(); // reflects on the x-axis.
	void reflect_y(); // reflects on the y-axis.
	void rotate(double r); // rotates the function clockwise or counter clockwise. r is in radians.

	// Friend function
	friend istream& operator >> (istream& ins, point& target);
	friend ostream& operator << (ostream& outs, point& target);

	// Overloaded operands
	point& operator = (const point &obj);

};

point::point () {
	x_point = 0;
	y_point = 0;
}
point::point (double x, double y) {
	x_point = x;
	y_point = y;
}

void point::translate (double X, double Y) {
	x_point = (x_point + X);
	y_point = (y_point + Y);
}

void point::scale (double m) {
	x_point = (x_point*m);
	y_point = (y_point*m);
}

void point::reflect_x() {
	x_point = (x_point*(-1));
}

void point::reflect_y() {
	y_point = (y_point*(-1));
}

void point::rotate(double r) {
	double temp;
	temp = x_point;
	x_point = (temp*cos(r) - y_point*sin(r));
	y_point = (temp*sin(r) + y_point*cos(r));
}

// Friend function for input
// x_point and y_point are read from the ins and it returns the istream ins.
istream& operator >> (istream& ins, point& target) {
	ins >> target.x_point >> target.y_point;
	return ins;
}

// Friend function for output
// x_point and y_point are output from outs and it returns the ostream outs.
ostream& operator << (ostream& outs, point& target) {
	outs << target.x_point  << " " << target.y_point;
	return outs;
}

// Overloaded "==" operator.
bool operator == (point& obj_1, point& obj_2) {
	return (obj_1.get_x() == obj_2.get_x())
			&&
			(obj_1.get_y() == obj_2.get_y());
}

// Overloaded "=" operator.
point& point::operator = (const point &obj) {

	if(this != &obj)
	{
		x_point = obj.x_point;
		y_point = obj.y_point;
	}
	return *this;
}

#endif // POINT_H_INCLUDED
