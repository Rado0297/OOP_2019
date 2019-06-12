#include "CustomLib.hpp"

SVGDocument::SVGDocument()
{
	currentLine = 0;
	currentCircle = 0;
	currentRect = 0;

	lines = new Line[30];
	circles = new Circle[30];
	rects = new Rect[30];
}

SVGDocument::~SVGDocument()
{
	delete[] lines;
	delete[] circles;
	delete[] rects;
}

const void SVGDocument::printAllFigures() const
{
	for (int i = 0; i < currentCircle; ++i)
	{
		cout << "Circles index: " << i << " " << circles[i] << endl;
	}

	for (int i = 0; i < currentRect; ++i)
	{
		cout << "Rects index: " << i << " "  << rects[i] << endl;
	}

	for (int i = 0; i < currentLine; ++i)
	{
		cout << "Lines index: " << i << " "  << lines[i] << endl;
	}
}

void SVGDocument::addCircle(ifstream& _file, string line, char* _stroke, char* _fill)
{
	extractString(_file, line, "fill=\"", 6, _fill);
	extractString(_file, line, "stroke=\"", 8, _stroke);

	Circle obj_circle(extractNumber(_file, line, "cx=\"", 4),
		extractNumber(_file, line, "cy=\"", 4),
		extractNumber(_file, line, "r=\"", 3),
		extractNumber(_file, line, "stroke-width=\"", 14),
		_stroke,
		_fill);
	cout << obj_circle << endl;

	circles[currentCircle] = obj_circle;
	currentCircle++;
}

void SVGDocument::addRect(ifstream& _file, string line, char* _stroke, char* _fill)
{
	extractString(_file, line, "stroke=\"", 8, _stroke);
	extractString(_file, line, "fill=\"", 6, _fill);

	Rect obj_rect(extractNumber(_file, line, "x=\"", 3),
		extractNumber(_file, line, "y=\"", 3),
		extractNumber(_file, line, "stroke-width=\"", 14),
		_stroke,
		_fill,
		extractNumber(_file, line, "width=\"", 7),
		extractNumber(_file, line, "height=\"", 8));
	cout << obj_rect << endl;

	rects[currentRect] = obj_rect;
	currentRect++;
}

void SVGDocument::addLine(ifstream& _file, string line, char* _stroke)
{
	extractString(_file, line, "stroke=\"", 8, _stroke);

	Line obj_line(extractNumber(_file, line, "x1=\"", 4),
		extractNumber(_file, line, "y1=\"", 4),
		extractNumber(_file, line, "stroke-width=\"", 14),
		_stroke,
		extractNumber(_file, line, "x2=\"", 4),
		extractNumber(_file, line, "y2=\"", 4));
	cout << obj_line << endl;

	lines[currentLine] = obj_line;
	currentLine++;
}

void SVGDocument::translateAllFigures(double _tx, double _ty)
{
	for (int i = 0; i < currentCircle; ++i)
	{
		circles[i].translate(_tx, _ty);
	}

	for (int i = 0; i < currentRect; ++i)
	{
		rects[i].translate(_tx, _ty);
	}

	for (int i = 0; i < currentLine; ++i)
	{
		lines[i].translate(_tx, _ty);
	}

	cout << "All figures had been translated!\n";
}

void SVGDocument::onClose()
{
	reset();
}

//Getters
const int SVGDocument::getCoutOfFigures() const
{
	return currentLine + currentRect + currentCircle;
}

//For writing into a file
const void SVGDocument::getAllFigures(ofstream& _ofile) const
{
	for (int i = 0; i < currentCircle; ++i)
	{
		_ofile << '\t' << circles[i] << endl;
	}

	for (int i = 0; i < currentRect; ++i)
	{
		_ofile << '\t' << rects[i] << endl;
	}

	for (int i = 0; i < currentLine; ++i)
	{
		_ofile << '\t' << lines[i] << endl;
	}
}

//Extra functions
//Conver and extract methods
double SVGDocument::charToDouble(const char* content)
{
	double val = 0;

	double _len = strlen(content);

	bool ifDouble = false;

	int pos = -1;
	for (int i = 0; i < strlen(content); ++i)
	{
		if (content[i] == '.')
		{
			pos = i;
			break;
		}
	}

	if (pos == -1)
	{
		for (int i = 0; i < strlen(content); ++i)
		{
			_len--;
			val += pow(10, _len) * (content[i] - '0');
		}

		return val;
	}

	else if (pos >= 1 && pos < strlen(content))
	{
		int ind = pos;
		ind--;
		for (int i = 0; i < strlen(content); ++i)
		{
			if (i != pos)
			{
				val += pow(10, ind) * (content[i] - '0');
				ind--;
			}
		}

		return val;
	}

	else
	{
		cout << "Invalid input! Stroke with must start with a numeric symbol.\n";
		return -1;
	}
}

double SVGDocument::extractNumber(ifstream& _file, string _line, char* _content, int len)
{
	double result;

	int j = _line.find(_content);
	j += len;

	char* num = new char[10];
	assert("num != nullptr");
	int ind = 0;

	while (_line[j] != '\"' && _line.find(_content) < j)
	{
		
		num[ind] = _line[j];
		ind++;
		j++;
	}
	num[ind] = '\0';

	if (num[0] == '\0')
	{
		result = 0;
	}
	else
	{
		result = charToDouble(num);
	}

	delete[] num;

	return result;
}

void SVGDocument::extractString(ifstream& _file, string _line, char* _content, int len, char* _fill_or_stroke)
{
	if (strcmp(_content, "") == 0)
	{
		cout << "String is empty\n";
		_fill_or_stroke[0] = '\0';
		return;
	}

	int j = _line.find(_content);

	j += len;

	int ind = 0;

	while (_line[j] != '\"' && _line.find(_content) < j)
	{
		_fill_or_stroke[ind] = _line[j];
		ind++;
		j++;
	}
	_fill_or_stroke[ind] = '\0';
}