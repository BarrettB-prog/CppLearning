/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip> //new library
using namespace std;

int main()
{
    // declaring vars
    int num1,num2,num3;
    double average;
    
    cout << "enter 3 numbers: "; 
    cin >> num1 >> num2 >> num3; 
    average = (num1 + num2 + num3) / 3.0;
    cout << fixed << showpoint << setprecision(3);
    
    cout << "the average is : " << average << endl;
    
    // formula = (F -32) * 5.0/9 - need to put 5.0 to print decimals
 
    return 0;
}
