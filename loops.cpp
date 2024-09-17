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
    
    int totalInches, inches, feet;
    
    cout << "how tall are you in inches? ";
    cin >> totalInches;
    
    if(totalInches > 0)
    {   
        feet = totalInches/12;
        inches = totalInches%12;
    
        cout << "you are: " << feet << " feet and " << inches << " inch";
    
    if(inches != 1)
        cout << "es";
    }
    else
        cout << "must enter a valid number";
        
     
    
    
    int number;
    cout << "1- print a happy message" << endl;
    cout << "2- print a so-so message" << endl;
    cout << "3- print a \"mean\" message" << endl;
    // the \" means "write it as a literal charater, not as an argument"
    
    cin >> number;
    
    while(number != 1 && number != 2 && number != 3) //checks if number is bad. "while" is a loop
    {
        cout << "bad entry try again" << endl;
        cin >> number;
    }
    
    if(number == 1)
        cout << "you're amazing" << endl;
    else if(number == 2)
        cout << "you can do better" << endl;
    else if(number == 3)
        cout << "you suck" << endl;
    
    
        
    int num = 1;
    
    while(num <= 1000)
    {
        cout << num << " ";
        
        if(num % 10 == 0)
        cout << endl;
        
        num++;
        
    }
    
    
    int value;
    cout << "enter a even number: ";
    cin >> value;
    
    while(value % 2 == 1 || value == 0)
    {
        cout << "try again..." << endl;
        cin >> value;
    }
    
    cout << "nice";

    return 0;
}

