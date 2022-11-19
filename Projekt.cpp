// Projekt.cpp: Definuje vstupní bod pro aplikaci.
//
#incl
#include "Projekt.h"
#include <conio.h>
#include <windows.h>

using namespace std;
int x = 1;
int main()
{
	while (x == 1)
	{
		int c = 122;
		//c = getch();
		if (c != 13)
			printf("%c", c);
		else
			printf("lol");
	}
}
