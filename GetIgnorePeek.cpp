/******************************************************************************

cin.ignore(); //ignore a set amount of chars
cin.get(); //read in a signle charater
cin.peek(); //read in a copy of the next charater



char ch1,ch2,ch3;
    string name;
    
    /*cin >> ch1;
    cin >> ch2;
    cin >> ch3;
    
    ch1 = cin.get();
    cin.get(ch2);
    ch3 = cin.get();
    //same thing, different syntax
    // preserves whitespace
    
    
    
    cout << ch1 << endl << ch2 << endl << ch3 << endl;
    
    cin.ignore(1000, '\n'); //ignores up to 1000 charaters or up to the new line. whatever is first
    cout << "what is your name ";
    cin >> name;
    cout << name << endl;
    
    // peek!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    double x;
    string str;
    char ch;
    
    cout << "enter something: ";
    ch = cin.peek();
    
    if(isdigit(ch) != 0)
    {
        cin >> x; //reads double into x
        cout << "read in the double: " << x << endl;
    }
    else
    {
        cin >> str;
        cout << "read in word: " << str << endl;
    }

*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    
    
    cin.ignore(); //ignore a set amount of chars
cin.get(); //read in a signle charater
cin.peek(); //read in a copy of the next charater



char ch1,ch2,ch3;
    string name;
    
    /*cin >> ch1;
    cin >> ch2;
    cin >> ch3;
    
    ch1 = cin.get();
    cin.get(ch2);
    ch3 = cin.get();
    //same thing, different syntax
    // preserves whitespace
    
    
    
    cout << ch1 << endl << ch2 << endl << ch3 << endl;
    
    cin.ignore(1000, '\n'); //ignores up to 1000 charaters or up to the new line. whatever is first
    cout << "what is your name ";
    cin >> name;
    cout << name << endl;
    
    // peek!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    double x;
    string str;
    char ch;
    
    cout << "enter something: ";
    ch = cin.peek();
    
    if(isdigit(ch) != 0)
    {
        cin >> x; //reads double into x
        cout << "read in the double: " << x << endl;
    }
    else
    {
        cin >> str;
        cout << "read in word: " << str << endl;
    }
    
   
    

    return 0;
}