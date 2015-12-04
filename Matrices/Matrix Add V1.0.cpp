#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NAME_LEN 10


typedef struct {
	int mat [MAX_ROWS] [MAX_COLS];
	int r,c; //rows cols
	char name [MAX_NAME_LEN];
}matType;

int addMatrices (matType A, matType B, matType *C){
	int r,c;
	
	if(A.r != B.r || A.c != B.c) return 0;
	
	for (r=1; r <= A.r;r++){
		for (c=1; c <= A.c; c++){
			C->mat[r][c] = A.mat[r][c] + B.mat[r][c];
			printf("Added A[%i][%i] to B[%i][%i], %i to %i",r,c,r,c,A.mat[r][c],B.mat[r][c]);
		}		
		printf("Moving on to row %i",r+1);
	}
	return 1;	
	C->r = A.r;
	C->c = A.c;
}

int matMult matType A, matType B, matType *C){
	int r,c,k;
	
	if(A.r != B.r || A.c != B.c) return 0;
	
	
	
	return 1;
}

int main(){
matType matA,matB,matResult;

addMatrices(A,B,matSum);



getch();
return 0;
}

