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
