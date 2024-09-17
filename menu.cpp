/******************************************************************************

Name: Barrett Bobilin
Date: 1/23/23
Assignment: Homework 1
Due Date: 1/26/23
About this project: creates a candy menu that allows for user inputs to
                    calculate the price of thier items, including tax
Assumptions: assumes correct user input

All work below was performed by Barrett Bobilin

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int
main ()
{
    // creating variables, including item prices and tax
    int Total;
    int numBeans;
    int numFrogs; 
    int numBon; 
    int numCake;
    const double BeanPrice = 4.00;
    const double FrogPrice = 1.50;
    const double BonPrice = 2.50;
    const double CakePrice = 6.25;
    const double TaxRate = 0.065;
    
    
    // listing items for sale and their prices
    cout << "\t Would you like anything from the trolly?" << endl << endl << endl;


    cout << "\t\t\t MENU" << endl;
    cout << "\t--------------------------------------" << endl;
    cout << "\t Bertie Botts Every Flavour Beans: $4.00" << endl;
    cout << "\t Chocolate Frog: $1.50" << endl;
    cout << "\t Exploding BonBons: $2.50" << endl;
    cout << "\t Cauldron Cake: $6.25" << endl;
    cout << "\t--------------------------------------" << endl;
    
    
    // creating options for user input
    cout << "I would like this many Beans --> ";
    cin >> numBeans; 
    cout << endl;
    
    cout << "I would like this many Frogs --> ";
    cin >> numFrogs;
    cout << endl;
    
    cout << "I would like this many Bons --> ";
    cin >> numBon;
    cout << endl;
    
    cout << "I would like this many Cakes --> ";
    cin >> numCake;
    cout << endl;
    
    
    // calculates the total price of the users desired food
    Total = (numBeans * BeanPrice) + (numFrogs * FrogPrice) + (numBon * BonPrice) + (numCake * CakePrice);
    
    // gives price without tax, and tax applied tovthe total
    cout << "Your pre-tax total is: $" << Total << endl;
    cout << "Tax is: $" << (Total * TaxRate) << endl;
    
    // just multiplies to get post-tax total
    double Final = Total * TaxRate;
    
    // final total
    cout << "Your final total is: $" << (Total + Final) << endl << endl;
    cout << "\tEnjoy!";
    
    // the statement below was my original formual and i didnt want to delete it
    //cout << (numBeans * BeanPrice) + (numFrogs * FrogPrice) + (numBon * BonPrice) + (numCake * CakePrice);



  return 0;
}

