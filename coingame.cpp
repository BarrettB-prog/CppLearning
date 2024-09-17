/* Name: Barrett Bobilin
Date: 2/12/2024
Assignment: coin game
Due Date: 2/15/2024
About this project: creates a game that allows the user to create a $ amount, and meet it using coins
Assumptions: they enter a normal amount to hit. so dollaramount != 1.343 or somthing that cant compute

All work below was performed by Barrett Bobilin */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int
main ()
{
  char play;
  double dollaramount;
  int numwins = 0;
  int numlosses = 0;
  double winpercent = 0;
  double HalfDollars = 0.50;
  double Quarters = 0.25;
  double Dimes = 0.10;
  double Nickels = 0.05;
  double Pennies = 0.01;
  int numHD;
  int numQ;
  int numD;
  int numN;
  int numP;
  double usertotal;
  int gamesplayed;
  double winrate = 0;

  
  cout << "Welcome to the coin game!" << endl;

  do
  {
    
    cout << "\nPlease enter a letter to play" << endl;
    cout << "p - play\ns - stats\nq - quit" << endl;
    cout << "\nChoice: ";
    cin >> play;
    cout << endl;
  
  while(play != 'p' && play != 'P' && play != 's' && play != 'S' && play != 'q' && play != 'Q')
  {
    cout << "invalid option" << endl;
    cout << "p - play\ns - stats\nq - quit" << endl;
    cout << "Choice: ";
    cin >> play;
  }
 
    if (play == 'p' || play == 'P')
    {
	  gamesplayed++;
	  cout << "Enter target amount $dd.cc: ";
	  cin >> dollaramount;
	  
	  while (dollaramount <= 0)
		{
		  cout << "Please enter a positive number." << endl;
		  cout << "\nEnter target amount $dd.cc: ";
		  cin >> dollaramount;
		}

     cout << fixed << showpoint << setprecision (2);
	 cout << "\nYou need to match the value of $" << dollaramount << endl;
	 cout << "Enter the number of: " << endl;
     cout << "Half Dollars: ";
     cin >> numHD;
     cout << endl << "Quarters: ";
     cin >> numQ;
     cout << endl << "Dimes: ";
     cin >> numD; 
     cout << endl << "Nickels: ";
     cin >> numN;
     cout << endl << "Pennies: ";
     cin >> numP;
     
      if(numHD >= 0 && numQ >= 0 && numD >= 0 && numN >= 0 && numP >= 0)
      {
     //math here
     usertotal = (numHD * HalfDollars) + (numQ * Quarters) + (numD * Dimes) + (numN * Nickels) + (numP * Pennies);
     
        if(usertotal == dollaramount)
        {
            cout << "\nyou win!";
            numwins++;
        }
        else if(usertotal != dollaramount)
        {
            cout << "you lost by: $" << abs(dollaramount - usertotal);
            numlosses++;
        }
      }
      else
        {
            cout << "\nCannot have negative coins, you lose";
            numlosses++;
        }
    }
    else if (play == 's' || play == 'S')
	{
	  cout << "\nWins: " << numwins << endl;
	  cout << "Losses: " << numlosses << endl;
	}
	else if(play == 'q' || play == 'Q')
	{
	    if(gamesplayed > 0)
	    {
	        winrate = (double)numwins/gamesplayed * 100;
	        cout << "\nFinal Stats:" << endl;
	        cout << "Wins: " << numwins << endl;
	        cout << "Losses: " << numlosses << endl;
	        cout << "Win Percentage: %" << winrate;
	    }
	    else if(gamesplayed == 0)
	    {
	    
	    cout << "guess you're too scared to play!" << endl;
	    cout << "\nFinal Stats:" << endl;
	    cout << "Wins: " << numwins << endl;
	    cout << "Losses: " << numlosses << endl;
	    cout << "Win Percentage: %" << winrate;
	    }
	}
   
  }while(play != 'q' && play != 'Q');

    //cout << "\nend";
    //cout << gamesplayed;

  return 0;
}

