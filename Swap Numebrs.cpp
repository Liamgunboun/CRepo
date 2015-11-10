#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>



void swap (int *x, int *y){
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;	
}



int main (){
	
	int x,y;
		
		
		printf("Please input first value: ");
		fflush(stdin);
		scanf("%i",&x);
		fflush(stdin);
		printf("Please input second value: ");
		fflush(stdin);
		scanf("%i",&y);
		
		printf("\n%i  %i",x,y);
		
		swap(&x,&y);
		
		printf("\n%i  %i",x,y);
		getch();
		
		return 0;
	
}
