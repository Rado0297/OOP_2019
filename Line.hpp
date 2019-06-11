class Line: public Shape
{
private:
	double x2;
	double y2;

	void copy(const Line& obj)
	{
		//Shape::copy(obj);
		x2 = obj.x2;
		y2 = obj.y2;
	}

public:
	Line(): Shape()
	{
		x2 = 200;
		y2 = 200;
	}

	Line(double _x1, double _y1, double _stroke_width, char* _stroke, double _x2, double _y2): Shape(_x1, _y1, _stroke_width, _stroke)
	{
		x2 = _x2;
		y2 = _y2;
	}

	Line(const Line& obj): Shape(obj)
	{
		copy(obj);
	}

	Line& operator=(const Line& obj)
	{
		if (this != &obj)
		{
			Shape::operator=(obj);
			copy(obj);
		}
	}

	~Line() {}

	//Print
	const void print() const;

	//Erase
	void erase();

	//Translate
	void translate(double, double);

	//Within
	void within();

	//Setters
	void setX2(double);

	void setY2(double);

	//Getters
	const double getX2() const;

	const double getY2() const;

	//Redefined operators << >>
	friend ostream& operator<<(ostream& out, const Line&);
	//friend istream& operator>>(istream& in, Line&);
};