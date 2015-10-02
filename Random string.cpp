#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_CHARS 80

int RandNum (int CharMin, int CharMax)
{
	return rand() % (CharMax-CharMin+1)+CharMin;	
}


int main()
{
	srand(time (NULL));
	int StrLen,MaxChar,MinChar;
	char RandString [MAX_CHARS]="";
	
	printf("Please Input The Min ASCII Character: \n");
	scanf("%i",&MinChar);
	printf("Please Input The Max ASCII Character: \n");
	scanf("%i",&MaxChar);
	
	StrLen=RandNum(1,MAX_CHARS);
	
	
	for (int i=0; i<StrLen; i++)
	{
		RandString[i]=RandNum(MinChar,MaxChar);
		if (i=StrLen-1)
			RandString[i]=0;
	}
	
	
	
	printf("%s",RandString);
	getch();
	
	
	
	
	return 0;
}
