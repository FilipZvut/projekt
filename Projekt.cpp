

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
		{
			printf("lol\n");
			x = 0;
		}
	}
	float iteresting = 0.11;
	for(int i = 0; i < 1000000; i++)
	{
		printf("%f\n %d\n", (10000000000*i*i*i*i*iteresting*i), i);
	}
}