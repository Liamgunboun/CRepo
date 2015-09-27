#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define ROWS 8
#define COLS 8

void DrawBoard (char ChessBoard[ROWS][COLS])
{
	HANDLE  hConsole;
	
	
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool White = false;
	system("cls");
    for(int i=0;i<ROWS;i++)
	{              
        for(int j=0;j<COLS;j++)
		{
            switch(White)
			{
				case true:
				SetConsoleTextAttribute(hConsole, 143);
    			printf(" %c",ChessBoard[j][i]);    				
    			break;
											
				case false:
				SetConsoleTextAttribute(hConsole, 127);
				printf(" %c",ChessBoard[j][i]);					
				break;
			}
            White = !White;
        }
        printf("\n");
        White = !White;
    }
	
              	

	   
	
	
}




int main () 
{
	char ChessBoard [ROWS][COLS];
	HANDLE  hConsole;	
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(int i=0;i<ROWS;i++){              
              for(int j=0;j<COLS;j++){            	
            		ChessBoard[i][j]=' '; 
              }             
    }
    
	DrawBoard(ChessBoard);
 
  getchar();  // wait
  return 0;
	

	
	
	
	
	
	
}
