/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
int
main ()
{
  
  int a = 9;
  int b;

  cout << "enter a number: ";
  cin >> b;

  cout << "the square root of a is: " << sqrt(a) << endl;
  cout << "the square root of b is: " << sqrt(b) << endl;
  
  
  int base, exp;
  cout << "enter the base: ";
  cin >> base;
  cout << "enter exponent: ";
  cin >> exp;
  cout << base << "^" << exp << " is: " << pow(base,exp) << endl;
  
  
  
  return 0;
}
