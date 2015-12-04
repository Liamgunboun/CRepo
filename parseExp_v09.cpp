/*
  This is a tricky piece of code to write ... up until now I have not tested
  any of helper functions ... probably should have tested these functions in
  isolation. For example, I probably should have started with the simpler ones
  and moved to the more complex ones. The most complex of all was the parseNum
  function.
  
  Anyway, lets finish what we started. Almost ready to test since parseNum is
  written. With my experience as a programmer, I would be very surprised if
  the parser works first try.
  
  Actually I see pointer errors right now! Lets fix them
  
  
  Wow ... on first run I just outputed the first operand in operand 1 ... it 
  printed the 2nd operand ... this is very good because error was easy to fix...
  just a copy and paste error inside parseExp ... anyone of you would have seen
  this error.
  
  Error fixed ... now outputing first operand ... now try full expression.
  
  For some reason when I tried to output the operator I got division everytime?
  WOW ... found the error in less than 1 minute ... back in university this type
  of error cost me nearly two hours once!
  
  DON'T USE = WHEN COMPARING SOMETHING! ... when checking if the opertor was
  the DIV op (to handle parenthesis that must follow a DIV op), I found an
  assignement operator rather than the equality relational operator.
  
  Yikes ... my code does not seem to handle negative numbers ... find the bug
  OMG ... a brutal error ... I have handle the number part of the operand in
  an else clause ... will never execute if negative sign encountered!
  
  fixed this but still doesn't handle negative numbers correctly ...
  example: entered -3/4 + -9/2 and output was -3/43 + -9/29 ... debug time
  
  Holy knucklehead!!!! ... preaching from my pedestal about not forgetting to 
  NULL terminate strings and what have I done!!!!
  
  WOW ... now it seems to be working ... due to my experience programming (and
  it isn't nearly as much as you might think given that I teach one section
  of ICS4UG per year and worked in the field one year), i was able to very 
  quickly and easily locate and fix my bugs.
  
  I admit that I have not thoroughly checked to see if I reject all types of 
  invalid input correctly. Maybe you guys can check this for me.
  
  NOTE ... nobody in this course would have written the parser this way. I have
  used pointers to pointers before and am reasonably comfortable working with
  them. You should keep and index inside parseExp to keep track of where you are\
  in the string ... just pass this index by reference to functions that help
  your parsing.
  
  Forgot to mention that my parser handles numbers of any length but will fail
  if the numbers exceed the capacity of a signed int.
*/

#include <stdio.h>
#include <stdlib.h>


#define OPEN_PARENTHESIS '('
#define ClOSED_PARENTHESIS ')'
#define NEG_SIGN '-'

#define ADD_OP '+'
#define SUB_OP '-'
#define MULT_OP '*'
#define DIV_OP '/'

#define MIN_NUM_CHAR '0'
#define MAX_NUM_CHAR '9'
#define SPACE_CHAR ' '


typedef char operatorType;
typedef struct {
  int n;
  int d;
  int r;  // reduced or not
} fractionType; 

typedef struct {
  fractionType op1, op2;
  operatorType op;
  fractionType answer;
} expType; 

int isNumChar (char c){
  return c >= MIN_NUM_CHAR && c <= MAX_NUM_CHAR;
}  

int parseNum (char **s, int *n){
  char temp [80];
  char neg = 0;
  int i;
  
  i = 0;
  if (**s == NEG_SIGN){
    temp[i] = NEG_SIGN;
    neg = 1;
    (*s)++;    // move past neg sign
    i++;
  }
  
  // get number portion ... can't believe i had this in an else clause
  while (isNumChar (**s)){
    temp [i] = **s;
    (*s)++;
    i++;
  }
  temp [i] = 0;    // NEVER FORGET TO NULL TERMINATE YOUR STRINGS  
  
  if (neg && i < 2) return 0;  // neg sign with no digits
  else if (i < 1) return 0;    // no digits  
  else{
    *n = atoi (temp);
    return 1;    // we got ourselves a number!
  }   
} 

int parseFraction (char **s, fractionType *f){
  int valid;
  
  valid = parseNum (s,&(f->n));
  if (!valid) return 0;
  
  if (**s == DIV_OP) (*s)++;
  else return 0;  // invalid fraction
  
  valid = parseNum (s,&(f->d));
  if (!valid) return 0;  
    
  return 1;
}  


int parseOperator (char **s, operatorType *op){
  switch (**s){
    case ADD_OP:;
    case SUB_OP:;
    case MULT_OP:;
    case DIV_OP:
      *op = **s;
      (*s)++;      // move past the operator in the string
      return 1;      // valid operator
    default: return 0;  // invalid operator
  }  
}  


void ignoreSpaces (char **s){
  while (**s == SPACE_CHAR) (*s)++;
}   


int parseExp (char *s, expType *exp){
  int valid;
  int parenthesis = 0;
  
  valid = parseFraction(&s,&(exp->op1));
  if (!valid) return 0;  // invalid operand 1
  
  ignoreSpaces (&s);
  
  valid = parseOperator (&s,&(exp->op));
  if (!valid) return 0; // invalid
  
  ignoreSpaces (&s);
  
  if (exp->op == DIV_OP){
    if (*s == OPEN_PARENTHESIS){
      parenthesis = 1;
      s++;
    } 
    else;
      return 0;  
  }
   
  valid = parseFraction(&s,&(exp->op2));  // copy/paste error here ... fixed now
  if (!valid) return 0;  // invalid operand 2
  
  // check for closing bracket
  if (exp->op == DIV_OP){
    if (*s == ClOSED_PARENTHESIS)
      return valid;
    else
      return 0;
  }
} 


void getExp (char *exp){
  printf ("Enter your expression: ");
  gets(exp); 
}


 
void outputExp (expType exp){
  printf ("%i/%i", exp.op1.n, exp.op1.d);
  printf (" %c ", exp.op);
  printf ("%i/%i", exp.op2.n, exp.op2.d);
}   


int main ()
{
  char expString[80];
  expType exp;
  int valid;
  
  while (1){    // temporary testing loop ... ignore bad indentation
  getExp (expString);
  valid = parseExp (expString, &exp);
  
  if (valid){
    outputExp (exp); 
    printf ("\n\n"); 
  }  
  else
    printf ("ERROR ... Invalid expression entered\n\n");
  
  }  
  
  system ("PAUSE");
  
}






