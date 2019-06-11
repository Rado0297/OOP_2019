class SVGDocument
{
private:
	Circle* circles;
	Rect* rects;
	Line* lines;

	int currentLine;
	int currentCircle;
	int currentRect;

public:
	SVGDocument();

	~SVGDocument();

	const void printAllFigures() const;
	void addCircle(ifstream& _file, string _line, char* _stroke, char* _fill);
	void addRect(ifstream& _file, string line, char* _stroke, char* _fill);
	void addLine(ifstream& _file, string line, char* _stroke);

	//Convert/Extract functions
	double charToDouble(const char* content);

	double extractNumber(ifstream& _file, string _line, char* _content, int len);

	void extractString(ifstream& _file, string _line, char* _content, int len, char* _fill_or_stroke);
};