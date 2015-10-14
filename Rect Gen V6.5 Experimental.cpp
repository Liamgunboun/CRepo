#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_RECTS 26
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
	char TempChar;
	struct Rectangle RandomRect;
	int ValidCount=0;
	printf("\n\nEnter the rectangle bottom: ");
	scanf("%i",  &RandomRect.Bot);
	printf("\n\nEnter the rectangle top: ");
	scanf("%i", &RandomRect.Top);
	printf("\n\nEnter the rectangle left: ");
	scanf("%i", &RandomRect.Left);
	printf("\n\nEnter the rectangle right: ");
	scanf("%i", &RandomRect.Right);	
	
	RandomRect.Name[0]  = 0;
	RandomRect.Name[1]  = 0;
	RandomRect.Name[2]  = 0;
	RandomRect.Name[3]  = 0;
	RandomRect.Name[4]  = 0;
	
	do{	
		system("cls");
		printf("\n\nEnter name. Cuts off if more than 4 chars:%s",RandomRect.Name );	
		TempChar = getch();
		if (TempChar >= 'a' and TempChar <= 'z'){
			RandomRect.Name[ValidCount]=TempChar;
			ValidCount++;
		}					
	} while (ValidCount<4);	
	return(RandomRect);
}

//Point Within?--------------------------------------------------------------------
const char *PointWithin(Rectangle Rect1,int X,int Y)
{	
	if (X>Rect1.Left && X<Rect1.Right && Y > Rect1.Bot && Y < Rect1.Top)
		return ("\n\nThe point is within the rectangle.\n");
	
	return ("\n\nThe point is not within the rectangle.\n");	
}

//Find Union--------------------------------------------------------------------

void Union (Rectangle Rect2,Rectangle Rect1){	
		printf("\n\nThe resulting rectangles points are: %i , %i    %i , %i\n\n",
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

//Sort by name 

void SortByName (Rectangle RandomRect[MAX_RECTS], int NumBoxes)
{
	struct Rectangle RandomRectT;
	int num=NumBoxes;
	for (int k = 3; k >= 0; k--){
		for (int i = 0; i < NumBoxes; i++)
		{
			for (int j = 0; j < NumBoxes; j++)
			{
				if (RandomRect[j].Name[k] > RandomRect[j+1].Name[k])
				{				
					RandomRectT=RandomRect[j];
					RandomRect[j]=RandomRect[j+1];
					RandomRect[j+1]=RandomRectT;
				}
				
			}
		
		}
	}
	
	PrintRect(RandomRect,num);
	printf("\n\nThats all of them sorted by name :D! Press Enter To Continue...");
	getch();
	system("cls");
	
}



// Find Intersection Points--------------------------------------------------------------------
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
		printf ("\n\nThey do not intersect :(....\n\n");
	}
}

// Rectangle Identifier--------------------------------------------------------------------

int RectIdentify (Rectangle RandomRects[MAX_RECTS], int NumBoxes )
{
	int RectNum1,RectNum2,ValidCount;
	bool Name1Found = false;
	char TempStr[4],TempChar;	
	ValidCount=0;
	TempStr[0]=0;
	TempStr[1]=0;
	TempStr[2]=0;
	TempStr[3]=0;
	TempStr[4]=0;
	
	do{	
		system("cls");
		PrintRect(RandomRects, NumBoxes);
		printf("\n\nEnter name of rectangle. Cuts off if more than 4 chars:%s",TempStr );	
		TempChar = getch();
		if (TempChar >= 'a' and TempChar <= 'z'){
			TempStr[ValidCount]=TempChar;
			ValidCount++;
		}					
	} while (ValidCount<4);
	
	TempStr[4]=0;
	
	for (RectNum1=0 ; RectNum1 < MAX_RECTS + 1 ; RectNum1 ++)
	{
	
	//Enable this to see what its checking	
	//	printf ("\n\n%s ---> %s : %i",RandomRects[RectNum1].Name,TempStr,strcmp(RandomRects[RectNum1].Name,TempStr));		
		
			if (strcmp(RandomRects[RectNum1].Name,TempStr) == 0)
			{			
				return (RectNum1);
				break;
			}
	}
		printf ("\n\n%s\n Is not a real rectangle. Returning to main menu.", TempStr);
		getch();
		return(100);	

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

	r.Bot   = 0;
	r.Top	= 0;
	r.Left  = 0;
	r.Right = 0;
	r.Name[0]  = 0;
	r.Name[1]  = 0;
	r.Name[2]  = 0;
	r.Name[3]  = 0;
	r.Name[4]  = 0;
	
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
		if (i <= NumBoxes)
			RandomRect[i] = GenRect();
		if 	(i >= NumBoxes)	
			RandomRect[i] = GenRect();
		
	}

	//Main Run Loop
	do
	{
		system("cls");
		PrintRect(RandomRect, NumBoxes);
		
		switch (menu())
		{
				case '1':	//Manual Entry
				if (NumBoxes==25) 
				{				
					system("cls");
					PrintRect(RandomRect, NumBoxes);
					printf("\n\n Too many rects. Press enter to begin entering the name of the rectangle you'd like to overwrite: ");
					getch();
					TempNum=RectIdentify(RandomRect, NumBoxes);
				}
				if (NumBoxes<25)
					TempNum=30;
				if (TempNum <= NumBoxes or TempNum == 30)
				{
					if (TempNum>NumBoxes)
					{						
						NumBoxes+=1;					
						RandomRect[NumBoxes-1]=ManualRect();
					} else {				
						RandomRect[TempNum]=ManualRect();
					}
					system("cls");
					printf("Action Successful! Press Enter!");
					getch();
				}
				break;
				
				
			case '2'://Delete Existing
				system("cls");
				PrintRect(RandomRect, NumBoxes);
				printf("\n\nPress enter to begin entering the name of the rectangle to delete...");
				getch();
				TempNum=RectIdentify(RandomRect, NumBoxes);
				system("cls");
				printf("\n\nDeleting. May Take a minute...");
				if (TempNum <= NumBoxes)
				{
					for (int i=TempNum; i <= NumBoxes; i++)
					{
						RandomRect[i]=RandomRect[i+1];
					}
					NumBoxes-=1;
					system("cls");
					printf("Action Successful! Press Enter!");
					getch();
				}
				break;
				
			case '3'://Intersection
				system("cls");
				PrintRect(RandomRect, NumBoxes);
				printf("\n\nPress enter to begin entering the name of the first rectangle to compare: ");
				getch();
				if (TempNum <= NumBoxes){				
					TempNum=RectIdentify(RandomRect, NumBoxes);
					printf("\n\nPress enter to begin entering the name of the second rectangle to compare: ");
					getch();
					TempNum2=RectIdentify(RandomRect, NumBoxes);
					if (TempNum <= NumBoxes && TempNum2 <= NumBoxes) {
						Intersection(RandomRect[TempNum],RandomRect[TempNum2]);
						getch();
						printf("\n\nAction Successful! Press Enter!");
						getch();
					}	
				}
				break;
			
			
			case '4'://Find Union
				system("cls");
				PrintRect(RandomRect, NumBoxes);
				printf("\n\nPress enter to begin entering the name of the first rectangle to compare: ");
				getch();
				TempNum=RectIdentify(RandomRect, NumBoxes);
				if (TempNum <= NumBoxes){
					printf("\n\nPress enter to begin entering the name of the second rectangle to compare: ");
					getch();
					TempNum2=RectIdentify(RandomRect, NumBoxes);
					if (TempNum <= NumBoxes && TempNum2 <= NumBoxes) {
						Union(RandomRect[TempNum],RandomRect[TempNum2]);
						printf("\n\nAction Successful! Press Enter!");
						getch();
					}
				}
				break;
			
			
			case '5'://Sort by Name
				SortByName(RandomRect,NumBoxes);
				break;
				
				
			case '6':
				system("cls");//Point Within?
				PrintRect(RandomRect, NumBoxes);
				printf("\n\nPress enter to begin entering the name of the rectangle name to compare: ");
				TempNum3=RectIdentify(RandomRect, NumBoxes);
				if (TempNum <= NumBoxes){
					printf("\n\nEnter the X coodinate: ");
					scanf("%i",&TempNum);
					printf("\n\nEnter the Y coodinate: ");
					scanf("%i",&TempNum2);						
					printf("\n%s",PointWithin(RandomRect[TempNum3],TempNum,TempNum2));
					printf("\nAction Successful! Press Enter!");
					getch();
				}
				break;
				
				
			case '7'://Exit Prog
				Run=false;
				break;
			
			case '8': //For Debuggin what was goin wrong
				printf("\n\nEnter the rectangle name: ");
				TempNum=RectIdentify(RandomRect, NumBoxes);
				printf("Thats Rectangle Number %i", TempNum);
				break;
				
			default:
				printf("\n Either invalid selection :(");		
		}
	
	}while(Run==true);
		
	getch();
	return 0;
}
