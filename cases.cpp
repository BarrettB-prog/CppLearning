/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    
    /*
    int N,D;
    cout << "enter a numerator: ";
    cin >> N;
    cout << endl;
    
    cout << "enter a denomonator: ";
    cin >> D;
    cout << endl;
    
    if(D != 0)
    {
        cout << "you get: " << static_cast<double>(N) / D << endl;
    } 
    else
    {
        cout << "cant divide by 0";
    }
    // static cast turns the varible in question into a DIFFERENT TYPE of var, just for 1 calculation
    */
    
    /*
   
    int num1,num2;
    char symbol;
    
    cout << "equation: ";
    cin >> num1 >> symbol >> num2;
    
    if(symbol == '+')
    {
        cout << num1+num2 << endl;
    }
    else if(symbol == '-')
    {
        cout << num1-num2 << endl;
    }
    else if(symbol == '/')
    {
        cout << num1/num2 << endl;
    }
    else if(symbol == '*' || symbol == 'x' || symbol == 'X')
    {
        cout << num1*num2 << endl;
    }
    else
    {
        cout << "symbol not recognized";
    }
    
    */
    
    char symbol;
    int num1,num2;
    
    cout << "equation: ";
    cin >> num1 >> symbol >> num2;
    
    switch(symbol)
    {
        case '+':
             cout << num1+num2 << endl;
             break;
        case '-':
            cout << num1-num2 << endl;
             break;
        case '/':
             cout << (double)num1/num2 << endl;
              break;
        case '*':
            cout << num1*num2 << endl;
             break;
        default:
            cout << "invalid" << endl;
    }
    
    
    

    return 0;
}