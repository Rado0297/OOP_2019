#include "CustomLib.hpp"

Shape::Shape()
{
	x1 = 100;
	y1 = 100;

	stroke_width = 10;

	stroke = new char[strlen("black") + 1];
	assert(stroke != nullptr);
	strcpy(stroke, "black");
}

Shape::Shape(double _x1, double _y1, double _stroke_width, char* _stroke)
{
	x1 = _x1;
	y1 = _y1;
	stroke_width = _stroke_width;

	stroke = new char[strlen(_stroke) + 1];
	assert(stroke != nullptr);
	strcpy(stroke, _stroke);
}

Shape::Shape(const Shape& obj)
{
	copy(obj);
}

Shape& Shape::operator=(const Shape& obj)
{
	if (this != &obj)
	{
		copy(obj);
	}

	return *this;
}

Shape::~Shape()
{
	delete[] stroke;
}

//Print
const void Shape::print() const
{
	cout << "Shape::print()\n";
	cout << "x1: " << x1 << endl
		<< "y1: " << y1 << endl
		<< "stroke_width: " << stroke_width << endl
		<< "stroke: " << stroke << endl;
}

//Erase
void Shape::erase()
{
	cout << "Shape::erase()\n";
}

//Translate
void Shape::translate(double tx, double ty)
{
	cout << "Shape::translate()\n";

	this->x1 += tx;
	this->y1 += ty;
}

//Within
void Shape::within()
{
	cout << "Shape::within()\n";
}

//Setters
void Shape::setX1(double _x1)
{
	this->x1 = _x1;
}

void Shape::setY1(double _y1)
{
	this->y1 = _y1;
}

void Shape::setStrokeWidth(double _stroke_width)
{
	this->stroke_width = _stroke_width;
}

void Shape::setStroke(char* _stroke)
{
	delete[] this->stroke;
	this->stroke = new char[strlen(_stroke) + 1];
	assert(this->stroke != nullptr);
	strcpy(this->stroke, _stroke);
}

//Getters
const double Shape::getX1() const
{
	return x1;
}

const double Shape::getY1() const
{
	return y1;
}

const double Shape::getStrokeWidth() const
{
	return stroke_width;
}

const char* Shape::getStroke() const
{
	return stroke;
}

//Redefined operators << >>
ostream& operator<<(ostream& out, const Shape& obj)
{
	out << "Print object:\n"
		<< "x1: " << obj.getX1() << endl
		<< "y1: " << obj.getY1() << endl
		<< "Stroke: " << obj.getStroke() << endl
		<< "Stroke width: " << obj.getStrokeWidth() << endl;

	return out;
}

istream& operator>>(istream& in, Shape& obj)
{
	int size = 0;
	cout << "Enter the size of string for stroke color: ";
	in >> size;
	in.get();
	
	double _x1, _y1, _stroke_width;
	char* _stroke = new char[size + 1];
	assert(_stroke != nullptr);

	//cout << "x1: ";
	in >> _x1;
	in.get();

	//cout << "y1: ";
	in >> _y1;
	in.get();

	//cout << "Stroke width: ";
	in >> _stroke_width;
	in.get();

	//cout << "Stroke: ";
	in >> _stroke;
	in.get();

	obj.setX1(_x1);
	obj.setY1(_y1);
	obj.setStrokeWidth(_stroke_width);
	obj.setStroke(_stroke);

	delete[] _stroke;

	return in;
}