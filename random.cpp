#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function for rolling 2 dice and adding the sum of them
int roll2();
//fucntion that simulates flipping a coin x number of times and prints num of heads and tails
void flipXtimes(int);
//function that welcomes user to the program


int main()
{
   
   srand(time(0));
   
   int user;
   int howmany;
   
   cout << "welcome to the sim!" << endl;
   cout << "1. Roll 2 dice \n2. Flip X number of coins" << endl;
   cin >> user;
   
   if(user == 1)
   {
       cout << "the sum is " << roll2();
       
   }
   else if (user == 2)
   {
       cout << "how many times: ";
       cin >> howmany;
       flipXtimes(howmany);
   }
   
   
//function for rolling 2 dice and adding the sum of them

//fucntion that simulates flipping a coin x number of times and prints num of heads and tails

//function that welcomes user to the program

    
    int r;
    
    //seed random number gen. "starting the gen"
    //stands for seed random. only do this once. the time thing pulls the time for the computer to run the function
    srand(time(0));
    
    
    cout << "role a die (1-6): " << rand() % 6 + 1 << endl;
    cout << "flip a coin (heads or tails): ";
    r = rand() % 2;
    if(r == 0)  
        cout << "heads" << endl;
    else
        cout << "tails" << endl;
        
    cout << "lotto number (1-65): " << rand() % 65 + 1 << endl;
    
    cout << rand() % 6 + 5 << endl;
    cout << rand() % 6 -3 << endl;
    
    cout << "lotto number (1-65): ";
    
    for(int i = 0; i < 6; i++)
        cout << rand() % 65 + 1 << " ";
        
    cout << endl;
   
   
   

    return 0;
}


int roll2()
{
   int a,b;
   a = rand() % 6 + 1;
   b = rand() % 6 + 1 ;
   return a+b;
}

void flipXtimes(int x)
{
    
    int r, heads = 0, tails = 0;
    for(int i =0; i < x; i++)
    {
      r = rand() % 2;
      if(r == 0)
        heads++;
      else
        tails++;
    }
    
    cout << "heads: " << heads << endl;
    cout << "tails: " << tails << endl;
    return;
}

    
    

