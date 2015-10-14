#include <stdio.h>
#include <stdlib.h>
#include <conio.h>




int main ()
{
	int Num;
	
	scanf("%i",Num);
	
	switch (Num){
		case (Num % 15 = 0):
			cout<<"FizzBuzz"<<endl;
			break;
		case Num % 5 == 0:
			cout<<"Buzz"<<endl;
			break;
		case Num % 3 == 0:
			cout<<"Fizz"<<endl;
			break;
		default:
			cout<<Num<<endl;
			break;
	}
		
	
	return 0;
	
}
