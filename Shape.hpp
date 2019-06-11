class Shape
{
protected:
	//Start point and/or center
	double x1;
	double y1;

	double stroke_width;
	char* stroke;

	void copy(const Shape& obj)
	{
		//cout << "Shape::copy()\n";
		x1 = obj.x1;
		y1 = obj.y1;
		stroke_width = obj.stroke_width;

		delete[] stroke;
		stroke = new char[strlen(obj.stroke) + 1];
		assert(stroke != nullptr);
		strcpy(stroke, obj.stroke);
	}

public:
	//Create
	Shape();

	Shape(double, double, double, char*);

	Shape(const Shape&);

	Shape& operator=(const Shape&);

	~Shape();
	
	//Print
	const void print() const;

	//Erase
	void erase();

	//Translate
	virtual void translate(double, double) = 0;

	//Within
	void within();

	//Setters
	void setX1(double);

	void setY1(double);

	void setStrokeWidth(double);

	void setStroke(char*);

	//Getters
	const double getX1() const;

	const double getY1() const;

	const double getStrokeWidth() const;

	const char* getStroke() const;

	//Redefined operators << >>
	friend ostream& operator<<(ostream& out, const Shape& obj);
	friend istream& operator>>(istream& in, Shape& obj);
};