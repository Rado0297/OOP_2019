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
	void translateFigure(double _tx, double _ty);

	//Within

	//Close
	void closeFile();

	//Save

	//SaveAs

	//Help
	const void helpMenu() const;

	//Exclusive messages
	const void openedFileRequired() const;

	const void invalidOperation() const;
};