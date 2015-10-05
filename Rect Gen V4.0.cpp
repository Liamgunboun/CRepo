#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

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
	printf("\n\nEnter the rectangle bottom: ");
	scanf("%i",  &RandomRect.Bot);
	printf("\n\nEnter the rectangle top: ");
	scanf("%i", &RandomRect.Top);
	printf("\n\nEnter the rectangle left: ");
	scanf("%i", &RandomRect.Left);
	printf("\n\nEnter the rectangle right: ");
	scanf("%i", &RandomRect.Right);
	
	  
	printf("\n\nEnter name. Cuts off if more than 4 chars ");
	scanf("%s", &RandomRect.Name);	
	RandomRect.Name[4]  = 0;
	
	return(RandomRect);
}

//Point Within?
string PointWithin(Rectangle Rect1,int X,int Y){
	
	if (X>Rect1.Left && X<Rect1.Right && Y > Rect1.Bot && Y < Rect1.Top)
		return ("The point is within the rectangle.");
	
	return ("The point is not within the rectangle.");
	
}

//Show Rects.------------------------------------------------------------------

void PrintRect (Rectangle RandomRect[MAX_RECTS], int NumBoxes)
{
	for (int i=0; i < NumBoxes; i++ )
	{	
	printf("\n%i %s =    Bottom Left %i , %i    Top Right %i , %i",i+1,RandomRect[i].Name, RandomRect[i].Left, RandomRect[i].Bot, RandomRect[i].Right, RandomRect[i].Top);	
	}
}


// Find Intersection Points
void Intersection (Rectangle Rect2,Rectangle Rect1)
{
	
	if (Rect1.Left < Rect2.Right && Rect1.Bot < Rect2.Top && Rect2.Left < Rect1.Right && Rect2.Bot < Rect1.Top || Rect2.Left < Rect1.Right && Rect2.Bot < Rect1.Top && Rect1.Left < Rect2.Right && Rect1.Bot < Rect2.Top)
		printf("The resulting rectangles points are: %i , %i    %i , %i",(Rect1.Left < Rect2.Left)?Rect2.Left:Rect1.Left,  (Rect1.Bot < Rect2.Bot)?Rect2.Bot:Rect1.Bot,  (Rect1.Right > Rect2.Right)?Rect2.Right:Rect1.Right,  (Rect1.Top > Rect2.Top)?Rect2.Top:Rect1.Top);
}


//Main Function--------------------------------------------------------------------------------
int main()
{
	srand(time (NULL));
	struct Rectangle RandomRect[MAX_RECTS];
	Rectangle r;
	bool Run = true;
	int NumBoxes= 100;
	int TempNum,TempNum2,TempNum3;
	
	//How many you want?
	while (NumBoxes>25)
	{
	printf(" How many boxes you want? (max 25): ");
	scanf("%i",&NumBoxes);
	}
	
	//Initialize Boxes
	for (int i=0; i < MAX_RECTS; i++)
	{	
		RandomRect[i] = GenRect();		
	}
	
	//Main Run Loop
	while (Run=true)
	{

		printf("%i",NumBoxes);
		PrintRect(RandomRect, NumBoxes);
		
		switch (menu())
		{
			case '1':
				printf("\n\nEnter the rectangle number you'd like to write to: ");
				scanf("%i",&TempNum);
				if (TempNum>NumBoxes)
				{
					NumBoxes+=1;
					RandomRect[NumBoxes-1]=ManualRect();
				} else {				
					RandomRect[TempNum-1]=ManualRect();
				}
				break;
				
			case '2':
				printf("\n\nEnter the rectangle number you'd like to delete: ");
				scanf("%i",&TempNum);
				for (int i=0; i < (NumBoxes); i++)
				{
					RandomRect[TempNum-2+i]=RandomRect[TempNum-1+i];
				}
				NumBoxes-=1;
				break;
				
			case '3':
				printf("\n\nEnter the first rectangle to compare: ");
				scanf("%i",&TempNum);
				printf("\n\nEnter the second rectangle to compare: ");
				scanf("%i",&TempNum2);
				Intersection(RandomRect[TempNum-1],RandomRect[TempNum2-1]);
				break;
				
			case '6':
				printf("\n\nEnter the X coodinate: ");
				scanf("%i",&TempNum);
				printf("\n\nEnter the X coodinate: ");
				scanf("%i",&TempNum2);
				printf("\n\nEnter the rectangle to compare: ");
				scanf("%i",&TempNum3);
				
				printf("\n%s",PointWithin(RandomRect[TempNum3],TempNum,TempNum2))
				
			case '7':
				Run=false;
				break;
				
			default:
				printf("\n Either invalid selection or not yet implemented feature :(");		
		}
	
	}
		
	getch();
	return 0;
}
