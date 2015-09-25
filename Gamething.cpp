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


 
int main (){    
    SetConsoleTitle("Exploration :D");
    char Board     [ROWS][COLS];
    char Items     [INV] [INV]={"Potion","Axe","Sword"};
    char PlayerInv [INV][INV];
    char Inp;  
    int ChX = ROWS/2-1;
    int ChY = COLS/2-1;    
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
          printf("%s",PlayerInv[1]);
          if (getch()==224){
          switch(getch()) {
                      case '72':
                           if (ChY>0)
                           ChY--;
                           break;
                      case '80':
                           if (ChY<COLS-1)
                           ChY++;
                           break;
                      case '75':
                           if (ChX>0)
                           ChX--;
                           break;
                      case '77':
                           if (ChX<COLS-1)
                           ChX++;
                           break;  
                      default:
                              printf("\n");                    
                      }
          }
          switch(ChX,ChY){
              case (13|10):
                  strcpy("Sword", PlayerInv[1]);//Give Him sword
                  printf("You Got a sword!");
                  system("pause"); 
              default:
                  "\n";                         
          }
    }
                   
   
   
    return 0;
}
