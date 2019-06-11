class Rect: public Shape
{
private:
	double width;
	double height;
	char* fill;

	void copy(const Rect& obj)
	{
		//cout << "Rect::copy()\n";
		//Shape::copy(obj);
		width = obj.width;
		height = obj.height;

		delete[] fill;

		fill = new char[strlen(obj.fill) + 1];
		assert(fill != nullptr);
		strcpy(fill, obj.fill);
	}

public:
	Rect(): Shape()
	{
		width = 100;
		height = 100;

		fill = new char[strlen("black") + 1];
		assert(fill != nullptr);
		strcpy(fill, "black");
	}

	Rect(double _x1, double _y1, double _stroke_width, char* _stroke, char* _fill, double _width, double _height): Shape(_x1, _y1, _stroke_width, _stroke)
	{
		width = _width;
		height = _height;

		fill = new char[strlen(_fill) + 1];
		assert(fill != nullptr);
		strcpy(fill, _fill);
	}

	Rect(const Rect& obj): Shape(obj)
	{
		copy(obj);
	}

	Rect& operator=(const Rect& obj)
	{
		if (this != &obj)
		{
			Shape::operator=(obj);
			copy(obj);
		}

		return *this;
	}

	~Rect()
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

	//Getters
	const double getWidth() const;

	const double getHeight() const;

	const char* getFill() const;

	//Redefined operators << >>
	friend ostream& operator<<(ostream& out, const Rect&);
	//friend istream& operator>>(istream& in, Rect&);
};