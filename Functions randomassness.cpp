#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define NUM_ARRAY_LEN 20

int linSearch (int *A, int n, int key); //Walk through array till find key, return place
int binSearch (int *A, int n, int key); //Binary Search through sorted array
void deleteRange (char *S, int lo, int hi); //Delete through movement
int hexToDec ( char *hex, int numDigits); //Can only handle uppercase

int linSearch (int *A, int n, int key){
	
	for (int i=0; i<=n; i++)
		if (A[i]==key)
			return i;
	
	
	return -1;
}


int binSearch (int *A, int n, int key){

	int lo = 0;
	int hi = n;
	
	while (n!=0 && key > 0 && key < NUM_ARRAY_LEN*10){ //
		n = (hi+lo)/2;
		
		if (A[n]==key)
			return n;
		else if (A[n] > key){	
			printf ( "\n A at %i (%i)> key (%i)", n, A[n],key);
			hi = n;
			}
		else if (A[n] < key){
			printf ("\n A at %i (%i)< key (%i)", n, A[n],key);
			lo = n;		
			}
	}	
	
	printf("\n%i", A[NUM_ARRAY_LEN]);
	
	if (A[0]==key)
		return 0;
		
	if (A[NUM_ARRAY_LEN-1]==key) 
		return NUM_ARRAY_LEN; 
		
	return -1;
}






int main(){
int numRay[NUM_ARRAY_LEN];	
	
	for (int i=0; i<=NUM_ARRAY_LEN; i++)
		numRay[i]=i*10;
		
	printf("\nLin Search: Place %i, Value %i", linSearch(numRay,NUM_ARRAY_LEN,6), numRay[linSearch(numRay,NUM_ARRAY_LEN,6)]);
	printf("\nBin Search: Place %i, Value %i", binSearch(numRay,NUM_ARRAY_LEN,200), numRay[binSearch(numRay,NUM_ARRAY_LEN,200)]);
	getch();	


return 0;
}

