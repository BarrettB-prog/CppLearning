/* Name: Barrett Bobilin
Date: 2/26/2024
Assignment: football
Due Date: 2/26/2024
About this project: creates a game that allows the user to enter the stats of 2 players and compare them
Assumptions:  may assume all user entries are valid integer values.
              do  hanotve to account for impossible stat entries: example: 0 passing attempts and 10 touchdowns
              do not have to account for other impossibilities like -20 passing yards.

All work below was performed by Barrett Bobilin */
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void welcomeMessage();

double getPasserRating(int a, double b, double c, int d, int e);

int main()
{
    
    int ATT1;
    int COMP1;
    double YDS1;
    int TD1;
    int INT1;
    //i spent at least an hour trying to figure out how to run player A, store the #s 
    //and then run player B and compare. then i gave up and doubled the variables.
    int ATT2;
    int COMP2;
    double YDS2;
    int TD2;
    int INT2;
    
    char PlayAgain;
    int GamesPlayed = 0;

    do
    {
    
    welcomeMessage();
    
    cout << "\nEnter single game information for player A: " << endl;
    cout << "Attempts: ";
    cin >> ATT1;
    cout << "\nCompletions: ";
    cin >> COMP1;
    cout << "\nPassing Yards: ";
    cin >> YDS1;
    cout << "\nTouchdowns: ";
    cin >> TD1;
    cout << "\nInterceptions: ";
    cin >> INT1;
    
    cout << "\nEnter single game information for player B: " << endl;
    cout << "Attempts: ";
    cin >> ATT2;
    cout << "\nCompletions: ";
    cin >> COMP2;
    cout << "\nPassing Yards: ";
    cin >> YDS2;
    cout << "\nTouchdowns: ";
    cin >> TD2;
    cout << "\nInterceptions: ";
    cin >> INT2;
    
    cout << fixed << showpoint << setprecision(1);
    cout << endl << "Player A's single game passer rating: " << getPasserRating(COMP1, ATT1, YDS1, INT1, TD1) << endl;
    cout << endl << "Player B's single game passer rating: " << getPasserRating(COMP2, ATT2, YDS2, INT2, TD2) << endl;
    
    if(getPasserRating(COMP1, ATT1, YDS1, INT1, TD1) > getPasserRating(COMP2, ATT2, YDS2, INT2, TD2))
    {
        cout << "Player A was better than player B by: " << abs(getPasserRating(COMP1, ATT1, YDS1, INT1, TD1) - getPasserRating(COMP2, ATT2, YDS2, INT2, TD2));
        cout << endl;
    }
    else if(getPasserRating(COMP2, ATT2, YDS2, INT2, TD2) > getPasserRating(COMP1, ATT1, YDS1, INT1, TD1))
    {
        cout << "Player B was better than player A by: " << abs(getPasserRating(COMP2, ATT2, YDS2, INT2, TD2) - getPasserRating(COMP1, ATT1, YDS1, INT1, TD1));
        cout << endl;
    }
    else
        cout << "Player A and Player B had equal ratings";
    
    if(getPasserRating(COMP1, ATT1, YDS1, INT1, TD1) >= 158.3 && getPasserRating(COMP2, ATT2, YDS2, INT2, TD2) >= 158.3)
        cout << "\nBoth Player A and Player B had perfect games!";    
    else if(getPasserRating(COMP1, ATT1, YDS1, INT1, TD1) >= 158.3)
        cout << "\nPlayer A had a PERFECT passer rating";
    else if(getPasserRating(COMP2, ATT2, YDS2, INT2, TD2) >= 158.3)
        cout << "\nPlayer B had a PERFECT passer rating";
    
        
    GamesPlayed++;
        
    cout << "\nPlay again? (Y/N): ";
    cin >> PlayAgain;
    
    if(PlayAgain == 'n' || PlayAgain == 'N')
    {
        cout << "Thanks For Playing!";
    }
    else if(PlayAgain == 'Y' || PlayAgain == 'y')
        cout << "\n";
    else
    {
        cout << "Invalid Input... exiting program";
        PlayAgain = 'n';
    }
        
    }while(PlayAgain != 'n' && PlayAgain != 'N');
    
    
    if(GamesPlayed == 1)
        cout << "\nYou compared " << GamesPlayed << " pair of players.";
    else
        cout << "\nYou compared " << GamesPlayed << " pairs of players.";    
    return 0;
}


//prints the welcome message
void welcomeMessage()
{
    cout << "Welcome to the NFL Quarterback Passer Rating Calculator!" << endl;
    cout << "A perfect passer rating (158.3) requires at least: " << endl;
    cout << "77.5% completion percentage\n12.5 yards per attempt\n11.875% touchdown % per attempt\nNo interceptions";
    cout << endl;
    
}

double getPasserRating(int a, double b, double c, int d, int e)
{
    cout << fixed << showpoint << setprecision(1);
    // w,x,y,z are the a,b,c,d listed in the directions for passer rating. i just had a hard time keeping
    // the vars straight if i did it the the opposite way. 
    double v;
    double w;
    double x;
    double y;
    double z;
    
    /*
    a = COMP 
    b = ATT 
    c = YDS 
    d = INT 
    e = TD 
    */
    
    v = (a/b - 0.3) * 5.0;
    
    if(v > 2.375)
        v = 2.375;
    else if(v < 0)
        v = 0;
        
    //cout << "\n\n\n V IS EQUAL TO " << v << "-----";
        
    w = (c/b - 3.0) * 0.25;
   
    if(w > 2.375)
        w = 2.375;
    else if(w < 0)
        w = 0;
        
    //cout << "\n\n\n W IS EQUAL TO " << w << "-----"; 
    
    
    x = (e / b) * 20.0;
    
    if(x > 2.375)
        x = 2.375;
    else if(x < 0)
        x = 0;
    
        
    //cout << "\n\n\n x IS EQUAL TO " << x << "-----";   
        
    y = 2.375 - (d/b * 25.0);
    
    if(y < 0)
        y = 0;
    else if(y > 2.375)
        y = 2.375;
    
    z = ((v+w+x+y)/6.0) * 100.0;
    
    
    return z;
}


