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
	char Name[5];
	int Bot;
	int Top;
	int Left;
	int Right;	
};

//Random Number---------------------------------------------------------------------------------------
int RandNum (int CharMin, int CharMax)
{

	return rand() % (CharMax - CharMin + 1) + CharMin;	
}

//Menu For thing. Dont Really know if I needed to Make this. But W/E---------------------------------------
int menu()
{
	printf("\n\n\n1 = Manual Input New Rect \n2 = Delete Existing Rect \n3 = Find Intersection \n4 = Find Union \n5 = Sort By Name \n6 = Point In Rectangle \n7 = Quit\n\nSelection? : ");
	return (getch());
	
}

//Generate Rectangles_--------------------------------------------------------
Rectangle GenRect()
{
	struct Rectangle RandomRect;
	
	RandomRect.Bot   = RandNum (MPW_BOT,MPW_TOP-1);
	RandomRect.Top	 = RandNum (RandomRect.Bot+1,MPW_TOP);
	RandomRect.Left  = RandNum (MPW_LEFT,MPW_RIGHT-1);
	RandomRect.Right = RandNum (RandomRect.Left+1,MPW_TOP);
	for (int i=0; i<4; i++)
	{	
		RandomRect.Name[i]  = RandNum ('a','z');
	}	
	RandomRect.Name[4]  = 0;

return (RandomRect);
}

//Manual Input--------------------------------------------------------------------
Rectangle ManualRect ()
{
	struct Rectangle RandomRect;
	printf("\n\nEnter The Rectangle Bottom: ");
	scanf("%i",  &RandomRect.Bot);
	printf("\n\nEnter The Rectangle Top: ");
	scanf("%i", &RandomRect.Top);
	printf("\n\nEnter The Rectangle Left: ");
	scanf("%i", &RandomRect.Left);
	printf("\n\nEnter The Rectangle Right: ");
	scanf("%i", &RandomRect.Right);
	
	  
	//for (int i=0; i<4; i++)
//	{	
	printf("\n\nEnter Name. Cuts off if more than 4 chars ");
	scanf("%s", &RandomRect.Name);
//	}	
	RandomRect.Name[4]  = 0;
	
	return(RandomRect);
}

//Show Rects.------------------------------------------------------------------

void PrintRect (Rectangle RandomRect[MAX_RECTS], int NumBoxes)
{
	for (int i=0; i < NumBoxes; i++ )
	{	
	printf("\n%s = Bot %i, Top %i, Left %i, Right %i",RandomRect[i].Name, RandomRect[i].Bot, RandomRect[i].Top, RandomRect[i].Left, RandomRect[i].Right);	
	}
}



//Main Function--------------------------------------------------------------------------------
int main()
{
	srand(time (NULL));
	struct Rectangle RandomRect[MAX_RECTS];
	Rectangle r;
	int NumBoxes,TempNum;
	printf(" How many boxes you want? (max 25): ");
	scanf("%i",&NumBoxes);
	printf("%i",NumBoxes);

	r=GenRect();

	printf("\n%s = Bot %i, Top %i, Left %i, Right %i",r.Name, r.Bot, r.Top, r.Left,r.Right);	
	
	
	for (int i=0; i < NumBoxes; i++)
	{
		RandomRect[i] = GenRect();		
	}
	
	while (true){

	
		PrintRect(RandomRect, NumBoxes);
		
		switch (menu())
		{
			case '1':
				printf("\n\nEnter The Rectangle Number You'd Like To Write To: ");
				scanf("%i",&TempNum);
				RandomRect[TempNum-1]=ManualRect();
				break;
				
			default:
				printf("\n Either Invalid Selection or Not yet implemented feature :(");
		
		}
	
		getch();
		}
		
		getch();
	return 0;
}
