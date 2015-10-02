#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_RECTS 25
#define MPW_BOT  0
#define MPW_TOP  600
#define MPW_LEFT 0
#define MPW_RIGHT 800

struct Rectangle
{
	char Name[4];
	int Bot;
	int Top;
	int Left;
	int Right;	
};

//Random Number
int RandNum (int CharMin, int CharMax)
{
	return rand() % (CharMax - CharMin + 1) + CharMin;	
}

//Generate Rectangles
Rectangle GenRect()
{
	struct Rectangle RandomRect;
	
	RandomRect.Bot   = RandNum (MPW_BOT,MPW_TOP-1);
	RandomRect.Top	 = RandNum (RandomRect.Bot+1,MPW_TOP);
	RandomRect.Left  = RandNum (MPW_BOT,MPW_RIGHT-1);
	RandomRect.Right = RandNum (RandomRect.Left+1,MPW_TOP);
	for (int i=0; i<4; i++)
	{	
	RandomRect.Name[i]  = RandNum (65,122);
	}	
	RandomRect.Name[4]  = 0;
return (RandomRect);
}

//Show Rects
void PrintRect (Rectangle RandomRect[MAX_RECTS], int NumBoxes)
{
	for (int i=0; i < NumBoxes; i++ )
	{	
	printf("\n%s = Bot %i, Top %i, Left %i, Right %i",RandomRect[i].Name, RandomRect[i].Bot, RandomRect[i].Top, RandomRect[i].Left, RandomRect[i].Right);	
	}
}

//Main Function
int main()
{
	srand(time (NULL));
	struct Rectangle RandomRect[MAX_RECTS];
	int NumBoxes;
	printf(" How many boxes you want?: ");
	scanf("%i",&NumBoxes);
	printf("%i",NumBoxes);
	getch();
	
	
	
	for (int i=0; i < NumBoxes; i++)
	{
		RandomRect[i] = GenRect();		
	}
	
	PrintRect(RandomRect, NumBoxes);
	

	getch();
	return 0;
}
