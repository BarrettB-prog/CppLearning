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
