#include <iostream>

using namespace std;

int main()
{
    
  /*
    int value;
    cout << "enter a number: ";
    cin >> value;
    
    if(value % 2 == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }
    
    if(value > 0)
    {
        cout << "positivie" << endl;
    }
    else
    {
        cout << "negitive" << endl;
    }


    */
    char grade;
    cout << "enter your final grade: ";
    cin >> grade;
    cout << endl;
    
    if(grade == 'A')
    {
        cout << "perfect";
    }
    else if(grade == 'B')
    {
        cout << "good job";
    }
    else if(grade == 'C')
    {
        cout << "you could do better";
    }
    else if(grade == 'D')
    {
        cout << "come on man...";
    }
    


    return 0;
}
