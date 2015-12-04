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



//ADDING MATRICES LOL
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


///MULTIPLYING MATRICES LLOL
int matMult (matType A, matType B, matType *C){
	int r,c,k;
	
	if(A.r != B.r || A.c != B.c) return 0;
	
	//Any A.r in a for can be B.r
	for (r=1; r <= A.r;r++){
		for (c=1; c <= A.c; c++){
			for (k=1; k <= A.r; k++){			
			C->mat[r][c] = A.mat[r][k] * B.mat[r][c];
			printf("Multiplying A[%i][%i] to B[%i][%i], %i to %i",r,k,k,c,A.mat[r][k],B.mat[k][c]);
			}
		}		 
		printf("Moving on to row %i",r+1);
	}
	
	C->r = A.r;
	C->c = B.c;
		
	return 1;
}

void initMat(matType *mat, int row, int col){
	
	for (r=1; r <= row;r++){
		for (c=1; c <= col; c++){						
			mat->mat[r][c] = 0;
		}		 
	}	
	printf("Done Inistialization");
}



//MAIN LOOP
int main(){
	

matType matA,matB,matResult;

addMatrices(matA,matB,&matResult);



getch();
return 0;
}












