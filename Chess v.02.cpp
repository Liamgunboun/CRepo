#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define ROWS 8
#define COLS 8


void DrawBoard (char ChessBoard[ROWS][COLS][2])
{
	HANDLE  hConsole;
	
	
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool White = true;
	system("cls");
    for(int i=0;i<ROWS;i++)
	{              
        for(int j=0;j<COLS;j++)
		{
            switch(White)
			{
				case true:
					switch(ChessBoard[j][i][1])
					{					
						case 'b':
							SetConsoleTextAttribute(hConsole, 112);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;
    					case 'r':
    						SetConsoleTextAttribute(hConsole, 124);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;
    					default:
    						SetConsoleTextAttribute(hConsole, 127);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;
    					   						
					}
					break; 						
				case false:
					{					
						case 'b':
							SetConsoleTextAttribute(hConsole, 128);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;
    					case 'r':
    						SetConsoleTextAttribute(hConsole, 140);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;
    					default:
    						SetConsoleTextAttribute(hConsole, 128);
    						printf("%c",(i*10)+j,ChessBoard[j][i][0]);    				
    						break;    					
					}
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
	int ii,jj;
	char ChessBoard [ROWS][COLS][2];
	HANDLE  hConsole;	
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(int i=0;i<ROWS;i++){              
              for(int j=0;j<COLS;j++){   
			  		
					   	if ((i*10+j)>= 28 and (i*10+j) <= 46)
						{
							ChessBoard[i][j][0]=' ';            		
							ChessBoard[i][j][1]=' ';						
						}	else if	((i*10+j)>=28 and (i*10+j)%2==1) {
							ChessBoard[i][j][0]='o';            		
							ChessBoard[i][j][1]='b';						
						}   else if ((i*10+j)<=48 and (i*10+j)%2==1){
							ChessBoard[i][j][0]='o';            		
							ChessBoard[i][j][1]='r';
						}  
              }             
    }
    
	DrawBoard(ChessBoard);	
	getch();
	ChessBoard[6][2][1]='b';
	ChessBoard[6][2][0]='o';
	DrawBoard(ChessBoard);
	getch();
	ChessBoard[4][4][1]='r';
	ChessBoard[4][4][0]='o';	
	DrawBoard(ChessBoard);
	getch(); 
 
  getchar();  // wait
  return 0;
	

	
	
	
	
	
	
}
