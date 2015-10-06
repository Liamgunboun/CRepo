#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
##include <string.h>

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
const char *PointWithin(Rectangle Rect1,int X,int Y)
{	
	if (X>Rect1.Left && X<Rect1.Right && Y > Rect1.Bot && Y < Rect1.Top)
		return ("The point is within the rectangle.");
	
	return ("The point is not within the rectangle.");
	
	
}

//Find Union

void Union (Rectangle Rect2,Rectangle Rect1){
	
	//bool condition[8] = {Rect1.Left < Rect2.Right, Rect1.Bot < Rect2.Top, Rect2.Left < Rect1.Right, Rect2.Bot < Rect1.Top, Rect2.Left < Rect1.Right,
//	Rect2.Bot < Rect1.Top, Rect1.Left < Rect2.Right,Rect1.Bot < Rect2.Top};
//	bool condition2[4];	
	
//	if (condition[0] && condition[1] && condition[2] && condition[3] || condition[4] && condition[5] && condition[6] && condition[7]){

		printf("The resulting rectangles points are: %i , %i    %i , %i\n\n",
		(Rect1.Left > Rect2.Left) ? Rect2.Left:Rect1.Left, 
		(Rect1.Bot > Rect2.Bot) ? Rect2.Bot:Rect1.Bot,  
		(Rect1.Right < Rect2.Right) ? Rect2.Right:Rect1.Right, 
		(Rect1.Top < Rect2.Top) ? Rect2.Top:Rect1.Top);

	
	
	
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
	bool condition[8] = {Rect1.Left < Rect2.Right, Rect1.Bot < Rect2.Top, Rect2.Left < Rect1.Right, Rect2.Bot < Rect1.Top, Rect2.Left < Rect1.Right,
	Rect2.Bot < Rect1.Top, Rect1.Left < Rect2.Right,Rect1.Bot < Rect2.Top};
	bool condition2[4];	
	
	if (condition[0] && condition[1] && condition[2] && condition[3] || condition[4] && condition[5] && condition[6] && condition[7]){

		printf("The resulting rectangles points are: %i , %i    %i , %i\n\n",
		(Rect1.Left < Rect2.Left) ? Rect2.Left:Rect1.Left, 
		(Rect1.Bot < Rect2.Bot) ? Rect2.Bot:Rect1.Bot,  
		(Rect1.Right > Rect2.Right) ? Rect2.Right:Rect1.Right, 
		(Rect1.Top > Rect2.Top) ? Rect2.Top:Rect1.Top);
		 
	} else {
		printf ("They do not intersect :(....\n\n");
	}
}

// Rectangle Identifier

int RectIdentify (Rectangle RandomRects[MAX_RECTS])
{
	int RectNum1,RectNum2;
	bool Name1Found = false;
	char TempStr[5];
	TempStr[5]=0;
	
	while (true){
	TempStr=gets();
		if (strlen(TempStr)>4)
		{
			for (int i = 0; i<5; i++)
			{
				
			}
		
		}
	
	
	}
	
	printf("Fetching Rectangle....\n\n");
	

	
	for (RectNum1=0 ; RectNum1 < MAX_RECTS + 1 ; RectNum1 ++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (RandomRects[RectNum1].Name[i] != TempStr[i])
				break;
			if (RandomRects[RectNum1].Name[i] == TempStr[i] && i == 4)
			{			
				Name1Found = true;
				break;
			}
		}
		if (Name1Found == true)
			break;
		
	}
		
	
	
	return (RectNum1);
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
		fflush(stdin);
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

		PrintRect(RandomRect, NumBoxes);
		
		switch (menu())
		{
			case '1':
				printf("\n\nEnter the rectangle name you'd like to write to: ");
				TempNum=RectIdentify(RandomRect);
				if (TempNum>NumBoxes)
				{
					NumBoxes+=1;
					RandomRect[NumBoxes]=ManualRect();
				} else {				
					RandomRect[TempNum]=ManualRect();
				}
				getch();
				break;
				
			case '2':
				printf("\n\nEnter the rectangle name you'd like to delete: ");
				TempNum=RectIdentify(RandomRect);
				for (int i=0; i < (NumBoxes); i++)
				{
					RandomRect[TempNum-1+i]=RandomRect[TempNum+i];
				}
				NumBoxes-=1;
				getch();
				break;
				
			case '3':
				printf("\n\nEnter the first rectangle to compare: ");
				TempNum=RectIdentify(RandomRect);
				printf("\n\nEnter the second rectangle to compare: ");
				TempNum2=RectIdentify(RandomRect);
				Intersection(RandomRect[TempNum],RandomRect[TempNum2]);
				getch();
				
				break;
			
			case '4':
				printf("\n\nEnter the first rectangle to compare: ");
				TempNum=RectIdentify(RandomRect);
				printf("\n\nEnter the second rectangle to compare: ");
				TempNum2=RectIdentify(RandomRect);
				Union(RandomRect[TempNum],RandomRect[TempNum2]);
				getch();
				break;
				
			case '6':
				printf("\n\nEnter the rectangle name to compare: ");
				TempNum3=RectIdentify(RandomRect);
				printf("\n\nEnter the X coodinate: ");
				scanf("%i",&TempNum);
				printf("\n\nEnter the Y coodinate: ");
				scanf("%i",&TempNum2);				
				
				printf("\n%s",PointWithin(RandomRect[TempNum3],TempNum,TempNum2));
				getch();
				break;
				
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
