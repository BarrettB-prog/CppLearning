
#include <iostream>
using namespace std;

//declaring function
//return type   name(paramater list) 
double average(int a, int b, int c);



int main()
{
    int x,y,z;
    
    cout << "enter 3 numbers: ";
    cin >> x >> y >> z;
    //average(x,y,z) calls function to do work. so this one inputs x,y,z into average's a,b,c.
    cout << "average is: " << average(x,y,z) << endl;
    cout << "enter 3 numbers: ";
    cin >> x >> y >> z;
    cout << "average is: " << average(x,y,z) << endl;
    
    cout << "average of 4 9 and 100 is: " << average(4,9,100) << endl;
    
    
    return 0;
}

//function definition
double average(int a, int b, int c)
{
    double result = (a+b+c) / 3.0;
    return result; //send variable back
}