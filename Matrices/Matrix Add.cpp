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

int addMatrices (matType A, matType B, matType *c){
	int r,c;
	
	if(A.r != B.r || A.c != B.c) return 0;
}

int main(){


return 0;
}

