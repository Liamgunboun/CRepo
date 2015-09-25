#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    while (true){
          if (getch() == '\033') { // if the first value is esc
              getch(); // skip the [
              switch(getch()) { // the real value
                   case 'A':
                        printf("UP");
                         break;
                   case 'B':
                       printf("DOWN");
                        break;
                   case 'C':
                          printf("LEFT");
                        break;
                   case 'D':
                          printf("RIGHT");
                        break;
                   }
          }
    }
}
