/* 
Barrett Bobilin

*/
#include <iostream>

using namespace std;

int main()
{
   int favnumber; // variable declaration. creating the variable
   favnumber = 6; // variable initialization. gives it a value
   
   cout << "my favorite number is: " << favnumber << ". Thank you for reading"; 
   cout << endl;
   
   int value2 = 97;
   cout << "the value of value2 is " << value2; 
   cout << endl;
   
   cout << "value2 + favnumber is: " << value2 << " + " << favnumber << endl;
   
   const double pi = 3.14159; // "const" doesnt let you change the variable later in the program
   cout << "pi is: " << pi << endl;
   
   int number = 6; 
   char x; 
   
   cout << "the number is: " << number << endl;
   cout << "x is: " << x << endl << endl; 
   
   int num1, num2, num3, num4, num5;
   num1 = 4 ;
   num2 = -3;
   num3 = num1 - num2;
   num4 = 28;
   num5 = 0;
   
   cout << num1 << endl;
   cout << num2 << endl;
   cout << num3 << endl;
   cout << num4 << endl;
   cout << num5 << endl;
   
    int age;
    cout <<"how old are you?" << endl;
    cin >> age; // cin allows user input
    cout << "you are: " << age << " years old";
   
    return 0;
}
