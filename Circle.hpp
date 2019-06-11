class Circle : public Shape
{
private:
	double r;
	char* fill;

	void copy(const Circle& obj)
	{
		//Shape::copy(obj);

		r = obj.r;

		delete[] fill;
		
		fill = new char[strlen(obj.fill) + 1];
		assert(fill != nullptr);
		strcpy(fill, obj.fill);
	}

public:
	//Create
	Circle(): Shape()
	{
		r = 5;

		fill = new char[strlen("black") + 1];
		assert(fill != nullptr);
		strcpy(fill, "black");
	}

	Circle(double _cx, double _cy, double _r, double _stroke_width, char* _stroke, char* _fill): Shape(_cx, _cy, _stroke_width, _stroke)
	{
		r = _r;

		fill = new char[strlen(_fill) + 1];
		assert(fill != nullptr);
		strcpy(fill, _fill);
	}

	Circle(const Circle& obj): Shape(obj)
	{
		copy(obj);
	}

	Circle& operator=(const Circle& obj)
	{
		if (this != &obj)
		{
			Shape::operator=(obj);
			copy(obj);
		}
	}

	~Circle()
	{
		delete[] fill;
	}
	
	//Print
	const void print() const;

	//Erase
	void erase();

	//Translate
	void translate(double, double);

	//Within
	void within();

	//Setters
	void setRadius(double);

	void setFill(char*);

	//Getters
	const double getRadius() const;

	const char* getFill() const;

	//Redefined operators << >>
	friend ostream& operator<<(ostream& out, const Circle&);
	friend istream& operator>>(istream& in, Circle&);
};