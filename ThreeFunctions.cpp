#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_ARRAY 22

int countInRange (int numArray[MAX_ARRAY], int min, int max){
	int count=0;
	int loops=0;

	do{	
		if (numArray[loops] >= min && numArray[loops] <= max){
			count++;	
		}	
			
		loops++;
	}while (numArray[loops]!=0 && loops<=MAX_ARRAY);
	
	return (count);
}



int countChars (char charray[MAX_ARRAY], char idChar){
	int count=0;
	int loops=0;
	
	do{	
		if (charray[loops] == idChar)
			count++;
		loops++;
	}while (charray[loops]!=0 && loops<=MAX_ARRAY);
	
	return (count);
}

bool isPalindrome (char palin[]){
	int len = strlen(palin)-1;	
	for (int i = 0; i<len; i++){
		if (palin[i] != palin[len-i])
		{		
			printf("\nIt is not a palindrome");
			return false;
		}	
		
		i++;
		 
	}
	
	printf("\nIt is a palindrome");
	return true;
}

int main (){
	char charray[MAX_ARRAY];
	int numArray[MAX_ARRAY];
	int tempNum=21;
	int tempNum2;
	

	//Count Chars Block
	while (tempNum>20){	
		tempNum=21;
		printf("How many characters in the array?(MAX 20) ");
		scanf("%i",&tempNum);
	}
	
	for (int i=0; i<tempNum; i++){
		printf("\nPlease enter char #%i: ",i+1);
		fflush(stdin);
		scanf("%c",&charray[i]);
	}
	charray[tempNum]=0;	
	
	printf("Please enter char to check for: ");	
	tempNum=countChars(charray,getch());	
	printf("\n There are %i of them",tempNum);
	getch();
	printf("\n End of the count chars block.\n\n",tempNum);
	getch();	
	// End of Count Chars
	
	//Count In Range Block
	tempNum=21;
	while (tempNum>20){	
		tempNum=21;
		printf("How many numbers in the array?(MAX 20) ");
		scanf("%i",&tempNum);
	}
	
	for (int i=0; i<tempNum; i++){
		printf("\nPlease enter number #%i: ",i+1);
		fflush(stdin);
		scanf("%i",&numArray[i]);
	}
	numArray[tempNum]=0;	
	
	printf("Please enter min for range: ");	
	scanf("%i",&tempNum);
	printf("Please enter max for range: ");
	scanf("%i",&tempNum2);
	
	tempNum=countInRange(numArray,tempNum,tempNum2);	
	printf("\n There are %i of them",tempNum);
	getch();
	printf("\n End of the count in range block.\n\n",tempNum);
	getch();
	
	// End of Count In Range
	
	//Is palindrome block
	
	printf("\nPlease enter palindrome: ");
	fflush(stdin);
	gets(charray);

	isPalindrome(charray);
	getch();	
	
	
	return 0;
}
