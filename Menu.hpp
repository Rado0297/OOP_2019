class Menu
{
private:
	SVGDocument figures;

	bool isOpen = false;

	string options[11] = {
						"open",
						"print",
						"create",
						"erase",
						"translate",
						"within",
						"close",
						"save",
						"save_as",
						"Help",
						"Exit"};
	string command;
	char* path;

	ifstream _file;

	void changePath(const char* _path)
	{
		delete[] path;
		path = new char[strlen(_path) + 1];
		assert(path != nullptr);
		strcpy(path, _path);
	}

public:
	Menu();

	~Menu();

	//Getters
	const bool getStatus() const;

	const void listOptions() const;

	

	//Open
	void openFile(const char* _path);

	//Print all figures
	const SVGDocument& getFigures() const;

	//Create

	//Erase

	//Translate
	void translateFigures(double _tx, double _ty);

	//Within

	//Close
	void closeFile();

	//Save
	void saveFile();

	//SaveAs
	void saveAsFile(const char* path);

	//Help
	const void helpMenu() const;

	//Exclusive messages
	const void openedFileRequired() const;

	const void invalidOperation() const;
};