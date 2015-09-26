#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(){
bool moved = false;
	while (moved==false){
	 if (getch()==224){
	 	printf("we got here");
          switch(getch()) {
                      case '72':
                          printf("key pressed");
                           moved = true;
                           break;
                      case '80':
                           printf("key pressed");
                           moved = true;
                           break;
                      case '75':
                           printf("key pressed");
                           moved = true;
                           break;
                      case '77':
                         printf("key pressed");
                           moved = true;
                           break;                  
                      }
          }
      }	
      moved = false;
      system("pause");	
	
	
	return 0;
}
