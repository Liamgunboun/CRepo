#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define ROWS 20
#define COLS 20
#define INV 10
 
void DrawGrid (char GmBoard[ROWS][COLS], int CharX, int CharY){
     GmBoard[CharX][CharY]='@';
     system("cls");
     for(int i=0;i<ROWS;i++){              
              for(int j=0;j<COLS;j++){
                   printf("%c",GmBoard[j][i]);      
              }
              printf("\n");
    }
    printf("\nChx:%i ChY:%i\n",CharX,CharY);
     
}

void ArrowKeys(int *ChXP,int *ChYP){
	bool moved = false;
	while (moved==false){
	 if (getch()==224){
          switch(getch()) {
                      case 72:
                      	
                           if (*ChYP>0)						   
                           		*ChYP--;
                           moved = true;
                           break;
                       	   
                      case 80:
                           if (*ChYP < COLS-1)					
                          		 *ChYP++;
						   moved = true;
                           break;
                           
                      case 75:
                           if (*ChXP > 0)					   
                          		 *ChXP--;						   
                           moved = true;
                           break;
                           
                      case 77:
                           if (*ChXP < COLS-1)					   
                           		*ChXP++;                           
                           moved = true;
                           break;   
					       
                         }
                      }
         }
         printf("Char Y cord pointer : - %i -, Char x cord pointer : - %i -\n",&ChYP,&ChXP);
		 printf("Char Y Cord (normally 9): - %i - ,Char x Cord (normally 9): - %i -\n",*ChYP,*ChXP);
      moved = false;
      system("pause");
}
 
int main (){    
    SetConsoleTitle("Exploration :D");
    char Board     [ROWS][COLS];
    char Items     [INV] [INV]={"Potion","Axe","Sword"};
    char PlayerInv [INV][INV];
    char Inp;  
    int ChX = ROWS/2-1;
    int ChY = COLS/2-1;
	int *ChYP = &ChY;
	int *ChXP = &ChX;    
    //Initialize
    Board[ChX][ChY]='@';
    for(int i=0;i<ROWS;i++){              
              for(int j=0;j<COLS;j++){
                   Board[i][j]='#';  
                   if (i<10 and j<10)
                      PlayerInv[i][j]=' ';
              }             
    }

    //Move Him Around A Bit   
    while (true){  
          //Show The grid
          DrawGrid(Board, ChX, ChY);
          //Finding Where To Move Him  
          printf("Up(u) Down(d) Left(l) Or Right(r)?\n");      
          //scanf("%c",&Inp);
          Board[ChX][ChY]='#';
          //printf("%s",PlayerInv[1]);
           ArrowKeys(ChXP,ChYP);
           /*
          switch(ChX,ChY){
              case (13|10):
                  strcpy("Sword", PlayerInv[1]);//Give Him sword
                  printf("You Got a sword!");
                  system("pause"); 
              default:
                  "\n";                         
          }
          */
    }
                   
   
   
    return 0;
}
