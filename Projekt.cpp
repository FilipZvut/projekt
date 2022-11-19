// Projekt.cpp: Definuje vstupní bod pro aplikaci.
//

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
		c = getch();
		if (c != 13)
			printf("%c\n", c);
		else
			printf("lol\n");
	}
	double iteresting = 0.11;
	for(int i = 0; i <100; i++)
	{
		printf("%lf", iteresting);
	}
}
