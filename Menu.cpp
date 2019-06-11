#include "CustomLib.hpp"

Menu::Menu()
{

}


Menu::~Menu()
{
	delete[] path;
}

//Getters
const bool Menu::getStatus() const
{
	return isOpen;
}

//Methods
const void Menu::listOptions() const
{
	cout << "You can use the following commands:\n";
	for (int i = 0; i < 11; ++i)
	{
		cout << i+1 << ". " << options[i] << endl;
	}
}

//Open
void Menu::openFile(const char* _path)
{
	path = new char[strlen(_path) + 1];
	assert(path != nullptr);
	strcpy(path, _path);

	isOpen = true;

	_file.open(_path);

	string line;

	if (_file.is_open())
	{
		cout << "++++++++++++++++++++++++++++++++++++++\n";
		while (getline(_file, line))
		{
			char _stroke[16];
			char _fill[16];

			if (line.find("circle") != string::npos)
			{
				figures.addCircle(_file, line, _stroke, _fill);

				continue;
			}

			if (line.find("rect") != string::npos)
			{
				figures.addRect(_file, line, _stroke, _fill);

				continue;
			}

			if (line.find("line") != string::npos)
			{
				figures.addLine(_file, line, _stroke);

				continue;
			}
		}
		cout << "++++++++++++++++++++++++++++++++++++++\n";
	}

	_file.close();
}

//Print all figures
const SVGDocument& Menu::getFigures() const
{
	return figures;
}

//Create figure

//Erase figure

//Translate
void Menu::translateFigure(double _tx, double _ty)
{

}

//Within

//Close
void Menu::closeFile()
{
	isOpen = false;
	cout << "Successfully closed file " << path << endl;
}

//Save

//SaveAs

//Help
const void Menu::helpMenu() const
{
	cout << "==========================\n\n"
		<< "How to use every command:\n"
		<< "1. open - this commmand opens a file and extract all base figures from it. THE the command should be passed with path to your file in your local filesystem.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "2. print - this command print out all figures and it should be passed alone.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "3. create - this command creates a figure and it takes several parameters. First of them is the type of a figure and the rest parameters are based on the type of the figure.\nFor example, if the figure is rectangular - we should pass rect x coord., y coord, stroke stroke-width stroke fill width height.\nIf the figure is line -> line x1 y1 x2 y2 stroke stroke-width.\nIf we want to create circle -> circle cx cy radius fill stroke stroke-width."
		<< "----------------------------------------------------------------------------\n"
		<< "4. erase - it is recommende to use print and the erase, so you will see the list with all figures and then can type \"erase num\", where num is the number in front of a figure.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "5. translate - It translates all figures. The command is passed like this -> translate vertical=number horizontal=other_or_same_number\n"
		<< "----------------------------------------------------------------------------\n"
		<< "6. within\n"
		<< "----------------------------------------------------------------------------\n"
		<< "7. close - it is a command that closes an open file, clears all figures that had been loaded into the momory and then we can pass only exit or open.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "8. save - It sould be passed alone.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "9. save_as\n"
		<< "----------------------------------------------------------------------------\n"
		<< "10. Help - print out detailed information about the commands above her.\n"
		<< "----------------------------------------------------------------------------\n"
		<< "11. Exit - close the whole programm.\n\n"
		<< "==========================\n";
}

//Exclusive error messages
const void Menu::openedFileRequired() const
{
	cout << "You must open the file first, then use this command\n";
}

const void Menu::invalidOperation() const
{
	cout << "Invalid operation!\nPlease checkout our functionallities that we support!";
}