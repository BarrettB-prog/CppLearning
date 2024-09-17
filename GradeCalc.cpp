/******************************************************************************

Name: Barrett Bobilin
Date: 1/30/23
Assignment: Homework 1
Due Date: 2/5/23
About this project: creates a program that allows for user inputs to
                    calculate their final grade 
Assumptions: assumes correct user input

All work below was performed by Barrett Bobilin

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    // on the assignment page it says to make the possible points "int" but i couldnt get it to print
    // decimals so i made it a double. hope thats ok. call it ingenuity
    const double ASSIGNPTSPOSS = 700.0;
    const double MIDTERMPTSPOSS= 100.0;  
    const double REVELPTSPOSS = 500.0; 
    const double FINALPTSPOSS = 100.0;
   
    int assignmentpoints;
    int midtermpoints;
    int revelpoints;
    int finalexampoints;
    char extracredit;
    int extracreditPoints;
    
    double assignmentTotal;
    double midtermTotal;
    double revelTotal;
    double finalTotal;
    
    double FinalGrade;
    
    cout << "How many assignement points did you earn: ";
    cin >> assignmentpoints; 
    
    cout << "\nHow many points did you get on your midterm: ";
    cin >> midtermpoints;
    
    cout << "\nHow many points did you get on on revel: ";
    cin >> revelpoints;
    
    cout << "\nHow many points did you get on your final: ";
    cin >> finalexampoints;
    
    cout << "\nDid you earn extra credit?: ";
    cin >> extracredit;
    
    if(extracredit == 'y' || extracredit == 'Y')
    {
        cout << "\nHow many points did you get?: ";
        cin >> extracreditPoints;
    }
    else if(extracredit == 'n' || extracredit == 'N')
    {
        cout << "\nBetter luck next time";
    }
    else
    {
        cout << " ";
    }
    
  
    
    // the first 4 are to make sure its a y or n and the && statement prevents negative numbers
    
    if(extracredit == 'n' || extracredit == 'N')
    {
        cout << fixed << showpoint << setprecision(1);
        
        extracreditPoints = 0;
    
        assignmentTotal = ((( assignmentpoints + extracreditPoints) / ASSIGNPTSPOSS) * 0.4);
        revelTotal = (( revelpoints / REVELPTSPOSS) * 0.1);
        midtermTotal = (( midtermpoints / MIDTERMPTSPOSS) * 0.2);
        finalTotal = (( finalexampoints / FINALPTSPOSS) * 0.3);
    
        FinalGrade = ((assignmentTotal + revelTotal + midtermTotal + finalTotal) * 100.0);
    
        cout << "\n\nYour final grade is: " << FinalGrade << "%" << endl; 
    }
    else if((extracredit == 'y' || extracredit == 'Y') && extracreditPoints > 0) // the && prevents negative #s
    {
        cout << fixed << showpoint << setprecision(1);
    
        assignmentTotal = (((assignmentpoints + extracreditPoints) / ASSIGNPTSPOSS) * 0.4);
        revelTotal = (( revelpoints / REVELPTSPOSS) * 0.1);
        midtermTotal = (( midtermpoints / MIDTERMPTSPOSS) * 0.2);
        finalTotal = (( finalexampoints / FINALPTSPOSS) * 0.3);
    
        FinalGrade = ((assignmentTotal + revelTotal + midtermTotal + finalTotal) * 100.0);
    
        cout << "\n\nYour final grade is: " << FinalGrade << "%" << endl;  
    }    
    else   
    {    
        cout << "\nInvalid entry for extra credit points.";
    }
    
    if((FinalGrade >= 90 && extracreditPoints >= 0) && (extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N'))
    {
        cout << "\nCourse letter grade = A";
    }
    else if((FinalGrade >= 80 && extracreditPoints >= 0) && (extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N'))
    {
        cout << "\nCourse letter grade = B";
    }
    else if((FinalGrade >= 70 && extracreditPoints >= 0) && (extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N'))
    {
        cout <<"\nCourse letter grade = C";
    }
    else if((FinalGrade >= 60 && extracreditPoints >= 0) && (extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N'))
    {
        cout << "\nCourse letter grade = D";
    }
    else if((FinalGrade < 60 && FinalGrade >= 0 && extracreditPoints >= 0) && (extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N'))
    {
        cout << "\nCourse letter grade = F";
    }
    else
    {
        cout << " ";
    }
    
    // i know this fucntion is super redunant with the || and && but i couldnt get the 
    // "course letter grade" to NOT print if the extra credit was invalid otherwise
    
    
    
    /*
    if((extracredit == 'y' || extracredit == 'Y' || extracredit == 'n' || extracredit == 'N') && extracreditPoints > 0)
    {
        cout << fixed << showpoint << setprecision(2);
    
        assignmentTotal = ((( assignmentpoints + extracreditPoints) / ASSIGNPTSPOSS) * 0.4);
        revelTotal = (( revelpoints / REVELPTSPOSS) * 0.1);
        midtermTotal = (( midtermpoints / MIDTERMPTSPOSS) * 0.2);
        finalTotal = (( finalexampoints / FINALPTSPOSS) * 0.3);
    
        FinalGrade = ((assignmentTotal + revelTotal + midtermTotal + finalTotal) * 100.0);
    
        cout << "\n\nYour final grade is: " << FinalGrade << "%" << endl; 
    }
    else if(extracreditPoints < 0 || extracreditPoints > 100)
    {
        cout << "\nInvalid entry for extra credit points.";
    }
    
    */
    
    
    /*
    
    if(extracreditPoints < 0 || extracreditPoints > 100)
    {
        cout << "\nYou cannot have negitive extra credit points. Please try again.";
    }
    else if(extracredit != 'y' || extracredit != 'Y' || extracredit != 'n' || extracredit != 'N')
    {
        cout << "\n";
    }
    else
    {
        cout << fixed << showpoint << setprecision(2);
    
        assignmentTotal = ((( assignmentpoints + extracreditPoints) / ASSIGNPTSPOSS) * 0.4);
        revelTotal = (( revelpoints / REVELPTSPOSS) * 0.1);
        midtermTotal = (( midtermpoints / MIDTERMPTSPOSS) * 0.2);
        finalTotal = (( finalexampoints / FINALPTSPOSS) * 0.3);
    
        FinalGrade = ((assignmentTotal + revelTotal + midtermTotal + finalTotal) * 100.0);
    
        cout << "\n\nYour final grade is: " << FinalGrade << "%" << endl; 
    }
    
    */
    
    // ^ thats how i originally tried to prevent invalid extra credit entries.it sorta worked but if the
    // value was valid, it didnt run. 
    
    return 0;
}








