#include "Error.h"



Error::Error()
{
}

void Error::DisplayError(string error) {

	SetConsoleTextAttribute(hConsole, 12);
	cout << error << endl;
	SetConsoleTextAttribute(hConsole, 7);
}
