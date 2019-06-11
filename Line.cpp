#include "CustomLib.hpp"

//Print
const void Line::print() const
{
	Shape::print();
	cout << "x2: " << x2 << endl
		<< "y2: " << y2 << endl;
}

//Erase
void Line::erase()
{

}

//Translate
void Line::translate(double tx, double ty)
{
	this->x1 += tx;
	this->y1 += ty;
	this->x2 += tx;
	this->y2 += ty;
}

//Within
void Line::within()
{

}

//Setters
void Line::setX2(double _x2)
{
	this->x2 = _x2;
}

void Line::setY2(double _y2)
{
	this->y2 = _y2;
}

//Getters
const double Line::getX2() const
{
	return x2;
}

const double Line::getY2() const
{
	return y2;
}

ostream& operator<<(ostream& out, const Line& obj)
{
	//<line x1="100" y1="300" x2="300" y2="100" stroke="green" stroke-width="15.9"/>
	out << "<line x1=\"" << obj.getX1() << "\" "
		<< "y1=\"" << obj.getY1() << "\" "
		<< "x2=\"" << obj.getX2() << "\" "
		<< "y2=\"" << obj.getY2() << "\" "
		<< "stroke=\"" << obj.getStroke() << "\" "
		<< "stroke-width=\"" << obj.getStrokeWidth() << "\"/>";
}