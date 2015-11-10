#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>




int countMultiples ( int min, int max, int mult){
	//Assum mult >=1 and mult is int
	int multFound=0;
	
	int first = min;
	int count;
	
	while(first<=max&& !multFound) {
	if (first%mult==0)
	multFound=1;
	else 
	first ++;
	}
		
	
	if (!multFound) return 0;
	
	count=0;
	
	for (int i = first; i<=max; i=i+mult, count++);
	
	return(count);
	
	//return (max/mult) - (min-1/mult);
}


int main(){
int x,y,z,a;

printf("\nPlease Input Min: ");
scanf("%i",&y);

printf("\nPlease Input Max: ");
scanf("%i",&z);

printf("\nPlease Input Mult: ");
scanf("%i",&a);


 x = countMultiples(y,z,a) ;
printf("\n %i", x);

getch();
return(0);
}
