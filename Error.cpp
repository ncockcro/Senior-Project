#include "Error.h"



Error::Error()
{
}

void Error::DisplayError(string a_error) {

	SetConsoleTextAttribute(m_hConsole, 12);
	cout << a_error << endl;
	SetConsoleTextAttribute(m_hConsole, 7);
}
