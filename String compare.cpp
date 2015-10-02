#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main() 
{	
	char s1[20],s2[20];	
	printf("Hey there little guy\n Please Input the first string to compare: ");	
	gets(s1);
	printf("\n Please Input the second string to compare: ");
	gets(s2);	
	
	for (int i=0; i<21; i++) 
	{
		if (s1[i] != s2[i])
		{
			printf("%i", s1[i] - s2[i]);
			getch();
			break;
		}	
		
		if (s1[i] == 0 and s2[i] == 0)
		{
			printf("%i", 0);
			getch();
			break;
		}
	
	}
	return 0;
}
