#include <iostream>
using namespace std;

int main()
{
    
    bool positive = false;
    bool negative = false;
    bool even = false;
    bool odd = false;
    int num;
   
  do
  {
    cout << "enter an integer. enter 0 to quit: " << endl;
    cin >> num;
    
    if(num > 0)
        positive = true;
    else if(num < 0)
        negative = true;
        
    if(num % 2 == 0 && num != 0)
        even = true;
    else if(num % 2 == 1)
        odd = true;
        
      
  }while(num != 0);
  
    if(even == true)
    cout << "even number was entered" << endl;
  
    if(odd == true)
    cout << "odd number entered" << endl;
    
    if(negative == true)
        cout << "negative number entered" << endl;
    
    if(positive == true)
        cout << "positivie number entered";
   
   
   
   
   
   

    return 0;
}