class SVGDocument
{
private:
	Circle* circles;
	Rect* rects;
	Line* lines;

	int currentLine;
	int currentCircle;
	int currentRect;

	void reset()
	{
		currentLine = 0;
		currentCircle = 0;
		currentRect = 0;

		delete[] lines;
		delete[] circles;
		delete[] rects;

		lines = new Line[30];
		circles = new Circle[30];
		rects = new Rect[30];
	}

public:
	SVGDocument();

	~SVGDocument();

	const void printAllFigures() const;
	void addCircle(ifstream& _file, string _line, char* _stroke, char* _fill);
	void addRect(ifstream& _file, string line, char* _stroke, char* _fill);
	void addLine(ifstream& _file, string line, char* _stroke);

	void translateAllFigures(double _tx, double _ty);

	void onClose();

	//Getters
	const int getCoutOfFigures() const;
	const void getAllFigures(ofstream& _ofile) const;

	//Convert/Extract functions
	double charToDouble(const char* content);

	double extractNumber(ifstream& _file, string _line, char* _content, int len);

	void extractString(ifstream& _file, string _line, char* _content, int len, char* _fill_or_stroke);
};