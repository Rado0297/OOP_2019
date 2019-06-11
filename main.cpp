#include "CustomLib.hpp"

//Save
void _save()
{
	cout << "Save is here" << endl;
}

//Save as
void _saveAs()
{
	cout << "Save as is here" << endl;
}

template <typename T>
T& create(const T& fig)
{
	return fig;
}

int main()
{
	Menu main_menu;
	/*
	double figure;
	double coord_x1;
	double coord_y1;
	double coord_x2;
	double coord_y2;
	double radius;
	double width;
	double height;
	char stroke_color[12];
	char fill_color[12];

	int countOfCircles = 0;
	int countOfRects = 0;
	int countOfLines = 0;

	Circle s1;

	cin >> s1;
	cout << s1;

	Circle* circles_arr;
	Rect* rects_arr;
	Line* lines_arr;

	Circle circle1;
	cout << circle1 << endl; */

	char command[8];
	char path[65];
/*
char str1[2] = {'1', '\0'};
char str2[2] = {'1', '\0'};

	cout << str1[0] << endl;
	cout << str2[0] << endl;
	cout << str1[0]+str2[0] << endl;
*/


	//cin >> command >> path;

	//_open(path);

	while (1)
	{
		main_menu.listOptions();

		cout << "Please enter a option (exit to terminate): ";
		cout.flush();
		//cin.getline(command, 8);
		cin >> command;

		if (strcmp(command, "open") == 0 && !main_menu.getStatus())
		{
			cin >> path;

			main_menu.openFile(path);
			cout << main_menu.getStatus() << endl;
		}

		else if (strcmp(command, "close") == 0 && main_menu.getStatus())
		{
			main_menu.closeFile();
			cout << main_menu.getStatus() << endl;

		}

		else if (strcmp(command, "save") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 3" << endl;

			cout << "Path: " << path << endl;

			_save();
		}

		else if (strcmp(command, "save_as") == 0 && main_menu.getStatus())
		{
			cin >> path;

			cout << "Command: " << command << " was mapped to: 4" << endl;

			_saveAs();
		}

		else if (strcmp(command, "print") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 1.1" << endl;
			main_menu.getFigures().printAllFigures();
		}

		else if (strcmp(command, "create") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 1.1" << endl;

			if (strcmp(command, "line") == 0)
			{
				/*cin >> param1;
				cin >> param2;
				cin >> param3;
				cin >> param4;
				cin >> param7;
				cin >> param5;
				Line temp(param1, param2, param3, param7, param4, param5);
				cout << "Line was added to list with lines.\n";
				lines_arr[countOfLines] = temp;
				countOfLines++;*/
			}

			//TODO: Same as the above for Rects and Circles
		}

		else if (strcmp(command, "erase") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 1.1" << endl;
		}

		else if (strcmp(command, "translate") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 1.1" << endl;
		}

		else if (strcmp(command, "within") == 0 && main_menu.getStatus())
		{
			cout << "Command: " << command << " was mapped to: 1.1" << endl;
		}

		else if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0)
		{
			main_menu.helpMenu();
		}

		else if (strcmp(command, "exit") == 0 || strcmp(command, "Exit") == 0)
		{
			return 0;
		}

		else if (main_menu.getStatus())
		{
			main_menu.invalidOperation();
		}

		else if (!main_menu.getStatus())
		{
			main_menu.openedFileRequired();
			main_menu.invalidOperation();
		}
	}

	return 0;
}