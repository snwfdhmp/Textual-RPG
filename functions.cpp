#include "functions.h"



const char separatorChar = '=';

void printWithSeparators(string str) {
	int i;
	for (i = 0; i < str.length(); ++i)
	{
		cout << separatorChar;
	}
	cout << endl << str << endl;
	for (i = 0; i < str.length(); ++i)
	{
		cout << separatorChar;
	}
	cout << endl;
}
string color(int color) {
	if(USE_COLOR){
		return "\x1b[" + to_string(color) + "m";
	}
	return "";
}
void clearConsole() {
	int i = 0;
	for (i = 0; i < 100; ++i)
	{
		cout << endl;
	}
}