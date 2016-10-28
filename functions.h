#include <iostream>
#include <stdio.h> 
#include <string>

#define TRUE 1
#define FALSE 0
#define __unix__ //A commenter si vous n'utilisez pas unix
//#define WIN32 //A decommenter si vous utilisez un système Windows

#ifdef __unix__ 
/*

	Les codes ci-dessous correspondent aux différents codes couleur
	utilisés dans le programme. Certains sont inutiles, mais les
	avoir à disposition est toujours pratique en cas de besoin.
	Color = couleur texte
	Background = couleur background
	/!\ usage : cout << color(COLOR_RED) << "Vous êtes en danger";
	/!\ Ne pas oublier de remettre la couleur de base après avoir
	changé la couleur

*/
#define COLOR_BLACK 30
#define COLOR_RED 31
#define COLOR_GREEN 32
#define COLOR_YELLOW 33
#define COLOR_BLUE 34
#define COLOR_MAGENTA 35
#define COLOR_CYAN 36
#define COLOR_WHITE 37

#define BACKGROUND_BLACK 40
#define BACKGROUND_RED 41
#define BACKGROUND_GREEN 42
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLUE 44
#define BACKGROUND_MAGENTA 45
#define BACKGROUND_CYAN 46
#define BACKGROUND_WHITE 47


#elif defined(_WIN32) || defined(WIN32)

#endif

//CONFIG
#define USE_COLOR FALSE  //TRUE ou FALSE (vrai ou faux)

using namespace std;

void printWithSeparators(string str);
string color(int color);
void clearConsole();









