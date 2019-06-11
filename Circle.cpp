#include "CustomLib.hpp"

//Print
const void Circle::print() const
{
	cout << "Circle::print()\n";
	Shape::print();
	cout << "r: " << r << endl
		<< "fill: " << fill << endl;  
}

//Erase
void Circle::erase()
{
	cout << "Circle::erase()\n";
}

//Translate
void Circle::translate(double tx, double ty)
{
	cout << "Circle::translate()\n";

	this->x1 += tx;
	this->y1 += ty;
}

//Within
void Circle::within()
{
	cout << "Circle::within()\n";
}

//Setters
void Circle::setRadius(double _r)
{
	this->r = _r;
}

void Circle::setFill(char* _fill)
{
	delete[] this->fill;
	this->fill = new char[strlen(_fill) + 1];
	assert(this->fill != nullptr);
	strcpy(this->fill, _fill);
}

//Getters
const double Circle::getRadius() const
{
	return r;
}

const char* Circle::getFill() const
{
	return fill;
}

//Redefined operators << >>
ostream& operator<<(ostream& out, const Circle& obj)
{
	//<circle cx="5" cy="7" r="100" fill="red" stroke="black" stroke-width="9"/>
	out << "<circle cx=\"" << obj.getX1() << "\" "
		<< "cy=\"" << obj.getY1() << "\" "
		<< "stroke=\"" << obj.getStroke() << "\" "
		<< "stroke-width=\"" << obj.getStrokeWidth() << "\" "
		<< "r=\"" << obj.getRadius() << "\" "
		<< "fill=\"" << obj.getFill() << "\"/>";
}

istream& operator>>(istream& in, Circle& obj)
{
	int size = 0;
	cout << "Enter the size of string for stroke color: ";
	in >> size;
	in.get();

	int size2 = 0;
	cout << "Enter the size of string for fill color: ";
	in >> size2;
	in.get();
	
	double _x1, _y1, _stroke_width, _r;
	char* _stroke = new char[size + 1];
	assert(_stroke != nullptr);

	char* _fill = new char[size2 + 1];
	assert(_fill != nullptr);

	cout << "x1: ";
	in >> _x1;
	in.get();

	cout << "y1: ";
	in >> _y1;
	in.get();

	cout << "Stroke width: ";
	in >> _stroke_width;
	in.get();

	cout << "Stroke: ";
	in >> _stroke;
	in.get();

	cout << "Fill: ";
	in >> _fill;
	in.get();

	cout << "Radius: ";
	in >> _r;
	in.get();

	obj.setX1(_x1);
	obj.setY1(_y1);
	obj.setStrokeWidth(_stroke_width);
	obj.setStroke(_stroke);
	obj.setRadius(_r);
	obj.setFill(_fill);

	delete[] _stroke;
	delete[] _fill;

	return in;
}