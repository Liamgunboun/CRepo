/*
  Author:   [Your name goes here]
  Date:     Wednesday, Oct. 14, 2015
  
  An employee consists of 5 fields: an employee code (empCode), a password (pwd),
  a number of units sold field (unitsSold), a bonus field and a pay field. The 
  first three fields will be entered by the user, while the last two fields will
  be computed according to the given formula.
  
  By the end of the period a potential LEVEL 4* student will have completed 6
  versions of this program. There will be six files named employeeProgTest_v01,
  employeeProgTest_v02, ... employeeProgTest_v06. NO USER_DEFINED FUNCTIONS!
  After this test, we will jump into the topic of functions.
  
  Here are the fields complete with restrictions and how they are calculated.
  
Field         Restrictions
======        ============      
  
empCode       4 to 7 lowercase letters inclusive ... duplicates are allowed

pwd           exactly 5 chars consisting of any combination of lowercase, 
              uppercase or number characters
              
unitsSold     0 to 400 units sold inclusive

bonus         if you sell more than 300 units you get $275 bonus, otherwise
              you get no bonus
             
pay           pay = $5/unit sold * unitsSold + bonus    

I will define several constants for you so you do not have to worry about 
doing this yourself. If you choose to ignore the constants and use "magic
numbers" throughout your program, then you will limit your mark to a LEVEL 3.

Version 01
==========
Get up to a maximum of 50 user-defined employee records. The user will tell you
how many employees he wishes to enter.

Assume that ALL user input is valid in this version. 
Output the employee records using the formatting below:

empCode, pwd, unitSold, bonus, pay
Emp #1  jdlayyd, D2e8u, 120, ??, ??
Emp #2  juiq, 7Byy9, 235, ??, ??
Emp #3  rtbmni, 78u7Y, 398,??, ??
...

Note that the calculated fields must stored in the record. I was too lazy to
compute the calculated fields.

You will use this output format anytime you are asked to output the 
employee data.

Once done, save as employeeProgTest_v01. Immediately resave under the name
employeeProgTest_v02 and go to work on version 2. Be sure to store all six
versions in a folder title devlinj_OPT_01 but replace devlinj with your last
name and first initial.

Version 02
==========    
Implement unitsSold restrictions ... basically same program as version 1
except that now you cannot assume that the user will give you a valid
number of units sold. Obviously you can still expect valid empCode and
pwd data from the user. 

Once done, save as employeeProgTest_v02. Immediately resave under the name
employeeProgTest_v03 and go to work on version 3.

Version 03
==========  
Implement empCode restrictions ... basically same program as version 2
except that now you cannot assume that the user will give you a valid
empCode. It might be too short, too long OR have invalid characters. Obviously
you can still expect a valid pwd from the user.

Now you should understand how saving the versions works.

Version 04
==========
Implement pwd restrictions ... basically same program as version 3
except that now you cannot assume that the user will give you a valid
pwd. It might be too short, too long OR have invalid characters. Now you 
program does not expect valid input of any kind from the user. You are
checking everything.

Version 05
==========
Your boss now comes back to you and asks you why you are allowing duplicate
empCodes. To which you reply "because the requirements specifically say
duplicates are allowed". Now your boss tells you to fix the program anyway.

Implement code to make the empCode field unique for each employee ... in other
words don't allow duplicates anymore

Version 06
==========
Sort the records by empCode in alphabetical order (from a to z). Be sure to
output the records after sorting is complete. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program Constants ... I may not have thought of everything you need
#define MAX_EMPS 50         // min # of employees .. assume min is 0
#define MIN_EC_CHARS 4      // min # of chars in empCode
#define MAX_EC_CHARS 7      // max # of chars in empCode
#define PWD_CHARS 5         // # of chars in pwd
#define MIN_LC_CHAR 'a'     // min lowercase char
#define MAX_LC_CHAR 'z'     // max lowercase char
#define MIN_UC_CHAR 'A'     // min uppercase char
#define MAX_UC_CHAR 'Z'     // max uppercase char
#define MIN_NUM_CHAR '0'    // min number char
#define MAX_NUM_CHAR '9'    // max number char
#define MAX_UNITS_SOLD 400  // assume min units sold is 0
#define BONUS_THRESHOLD 300 // if you sell more than 300 units you get bonus
#define BONUS_VALUE 275     // the bonus is worth $275

// Feel free to use or ignore these constants
#define EC_PROMPT "Please enter a valid employee code: "
#define PWD_PROMPT "Please enter a valid password: "
#define UNITS_SOLD_PROMPT "Please enter a valid number of units sold: "
#define ERROR "INVALID INPUT ... Please try again"




// All of your code goes in main since you are not writing functions
int main (){
}  
