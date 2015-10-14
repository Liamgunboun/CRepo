#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main ()
{
	HANDLE  hConsole;
    

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool hello=true;
	
	for (int i=0;i<10;i++)
	{
		switch (hello)
		{
			case true:
				SetConsoleTextAttribute(hConsole, 143);
    			printf("hello");
    			break;
    		case false:
    			SetConsoleTextAttribute(hConsole, 127);
    			printf("hello");
    			break;
    	}
    	hello=!hello;
	} 
	
	
}
