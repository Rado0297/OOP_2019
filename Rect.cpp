#include "CustomLib.hpp"

//Print
const void Rect::print() const
{
	Shape::print();
	cout << "fill: " << fill << endl 
		<< "width: " << width << endl
		<< "height: " << height << endl;
}

//Erase
void Rect::erase()
{

}

//Translate
void Rect::translate(double tx, double ty)
{
	this->x1 += tx;
	this->y1 += ty;
}

//Within
void Rect::within()
{

}

//Getters
const double Rect::getWidth() const
{
	return width;
}

const double Rect::getHeight() const
{
	return height;
}

const char* Rect::getFill() const
{
	return fill;
}

ostream& operator<<(ostream& out, const Rect& obj)
{
	//<rect x="50" y="20" width="150" height="150" stroke="pink" fill="blue" stroke-width="5"/>
	out << "<rect x=\"" << obj.getX1() << "\" "
		<< "y=\"" << obj.getY1() << "\" "
		<< "width=\"" << obj.getWidth() << "\" "
		<< "height=\"" << obj.getHeight() << "\" "
		<< "fill=\"" << obj.getFill() << "\" "
		<< "stroke=\"" << obj.getStroke() << "\" "
		<< "stroke-width=\"" << obj.getStrokeWidth() << "\"/>";
}