#include "hourglass.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function declarations
void printInvertedTriangle(int S, char BorderChar, char FillChar);
void printTriangle(int S, char BorderChar, char FillChar);
void PrintHourglass(int S, char BorderChar, char FillChar);


// Constructor with parameters
Hourglass::Hourglass(int S, char BC, char FC)
{
    SetSize(S);
    SetBorder(BC);
    SetFill(FC);
}

// Draw function to display the hourglass
void Hourglass::Draw() const
{
    PrintHourglass(Size, BorderChar, FillChar);  
}

// Setters
void Hourglass::SetSize(int S)
{
    if (S < 1)
        Size = 1;
    else if (S > 39)
        Size = 39;
    else
        Size = S;
}

void Hourglass::SetBorder(char BC)
{
    BorderChar = BC;
}

void Hourglass::SetFill(char FC)
{
    FillChar = FC;
}

// Getters
int Hourglass::GetSize() const
{
   return Size; 
}

int Hourglass::GetPerimeter() const
{
    return 3 * Size * 2;  
}

double Hourglass::GetArea() const
{
    double area = (sqrt(3) / 2) * Size * Size * 2; 
    return area;
}

// Grow and Shrink functions
int Hourglass::Grow()
{
    if (Size < 39) 
    {
        Size++; 
    }
    return Size;
}

int Hourglass::Shrink()
{
    if (Size > 1) 
    {
        Size--; 
    }
    return Size;
}

// Summary
void Hourglass::Summary() const
{
    cout << "Size of hourglass's side = " << GetSize() << " units." << endl;
    cout << "Perimeter of hourglass = " << GetPerimeter() << " units." << endl;
    cout << "Area of hourglass = " << fixed << showpoint << setprecision(2) << GetArea() << " units." << endl;
    cout << "Hourglass looks like:" << endl;
    Draw();
}

// Print an inverted triangle for the upper part of the hourglass
void printInvertedTriangle(int S, char BorderChar, char FillChar)
{
    int SpaceIncrement = 1;

    while (S > 0)
    {
        for (int i = 0; i < SpaceIncrement - 1; ++i)
        {
            cout << " ";  // Leading spaces for alignment
        }

        for (int i = S; i > 0; --i)
        {
            if (S == i || i == 1) // Border characters
                cout << BorderChar << " ";
            else
                cout << FillChar << " "; // Fill characters
        }

        cout << "\n";
        SpaceIncrement++;
        S--;
    }
}

// Print a triangle for the lower part of the hourglass
void printTriangle(int S, char BorderChar, char FillChar)
{
    for (int i = 1; i < S; ++i)
    {
        for (int j = 0; j < S - i - 1; ++j)
        {
            cout << " ";  // Leading spaces for alignment
        }
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i) // Border characters
                cout << BorderChar << " ";
            else
                cout << FillChar << " "; // Fill characters
        }
        cout << "\n";
    }
}

// Print the full hourglass 
void PrintHourglass(int S, char BorderChar, char FillChar)
{
    printInvertedTriangle(S, BorderChar, FillChar);  // upper part of hourglass
    printTriangle(S, BorderChar, FillChar);          // lower part of hourglass
}
