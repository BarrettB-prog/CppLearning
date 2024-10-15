#include "distance.h"
#include <iostream>

using namespace std;

				// constants
const int INCHES_PER_FOOT = 12;
const int FEET_PER_YARD = 3;
const int YARDS_PER_MILE = 1760;

// simplify the distance object
void Distance::simplify() 
{
    if (inches >= INCHES_PER_FOOT) 
    {
        feet += inches / INCHES_PER_FOOT;
        inches %= INCHES_PER_FOOT;
    }
    if (feet >= FEET_PER_YARD) 
    {
        yards += feet / FEET_PER_YARD;
        feet %= FEET_PER_YARD;
    }
    if (yards >= YARDS_PER_MILE) 
    {
        miles += yards / YARDS_PER_MILE;
        yards %= YARDS_PER_MILE;
    }
}

// default constructor (0 distance)
Distance::Distance()
{
   miles = 0;
   yards = 0;
   feet = 0;
   inches = 0;
}

// constructor with inches input
Distance::Distance(int totalInches) : miles(0), yards(0), feet(0), inches(0)
{
    if (totalInches < 0) {
        totalInches = 0;
    }
    inches = totalInches;
    simplify();
}

// constructor with miles, yards, feet, inches input
Distance::Distance(int m, int y, int f, int i) : miles(m), yards(y), feet(f), inches(i)
{
    if (m < 0 || y < 0 || f < 0 || i < 0) {
        miles = yards = feet = inches = 0;
    }
    simplify();
}

// overload addition operator
Distance Distance::operator+(const Distance& other) const 
{
    Distance result(miles + other.miles, yards + other.yards, feet + other.feet, inches + other.inches);
    result.simplify();
    return result;
}

// overload subtraction operator
Distance Distance::operator-(const Distance& other) const 
{
    // convert both distances to total inches
    int totalInches1 = miles * YARDS_PER_MILE * FEET_PER_YARD * INCHES_PER_FOOT +  yards * FEET_PER_YARD * INCHES_PER_FOOT + feet * INCHES_PER_FOOT + inches;

    int totalInches2 = other.miles * YARDS_PER_MILE * FEET_PER_YARD * INCHES_PER_FOOT + other.yards * FEET_PER_YARD * INCHES_PER_FOOT + other.feet * INCHES_PER_FOOT + other.inches;

    // Return 0 if result is negative
    if (totalInches1 < totalInches2) 
    {
        return Distance(0);
    }

    return Distance(totalInches1 - totalInches2);
}

// overload multiplication operator
Distance Distance::operator*(int multiplier) const 
{
    int totalInches = miles * YARDS_PER_MILE * FEET_PER_YARD * INCHES_PER_FOOT + yards * FEET_PER_YARD * INCHES_PER_FOOT + feet * INCHES_PER_FOOT + inches;
   
    return Distance(totalInches * multiplier);
}

// overload comparison operators
bool Distance::operator<(const Distance& other) const 
{
    return (miles * YARDS_PER_MILE * FEET_PER_YARD * INCHES_PER_FOOT + 
           yards * FEET_PER_YARD * INCHES_PER_FOOT + 
            feet * INCHES_PER_FOOT + 
            inches) <
           (other.miles * YARDS_PER_MILE * FEET_PER_YARD * INCHES_PER_FOOT + 
            other.yards * FEET_PER_YARD * INCHES_PER_FOOT + 
            other.feet * INCHES_PER_FOOT + 
            other.inches);
}

bool Distance::operator>(const Distance& other) const 
{
    return other < *this;
}

bool Distance::operator<=(const Distance& other) const 
{
    return !(other < *this);
}

bool Distance::operator>=(const Distance& other) const 
{
    return !(*this < other);
}

bool Distance::operator==(const Distance& other) const 
{
    return (miles == other.miles && yards == other.yards && feet == other.feet && inches == other.inches);
}

bool Distance::operator!=(const Distance& other) const 
{
    return !(*this == other);
}

// Pre-increment
Distance& Distance::operator++() 
{
    ++inches;
    simplify();
    return *this;
}

// Post-increment
Distance Distance::operator++(int) 
{
    Distance temp = *this;
    ++inches;
    simplify();
    return temp;
}

// Pre-decrement
Distance& Distance::operator--() 
{
    if (miles == 0 && yards == 0 && feet == 0 && inches == 0) 
    {
        return *this;
    }
    --inches;
    simplify();
    return *this;
}

// Post-decrement
Distance Distance::operator--(int) 
{
    Distance temp = *this;
    if (miles == 0 && yards == 0 && feet == 0 && inches == 0) 
    {
        return temp;
    }
    --inches;
    simplify();
    return temp;
}


ostream& operator<<(ostream& os, const Distance& d) 
{
    os << "(";
    if (d.miles > 0) os << d.miles << "m ";
    if (d.yards > 0 || d.miles > 0) os << d.yards << "y ";
    if (d.feet > 0 || d.yards > 0 || d.miles > 0) os << d.feet << "' ";
    os << d.inches << "\")";
    return os;
}

istream& operator>>(istream& is, Distance& d) 
{
    char comma;  // to capture the commas
    int m, y, f, i;
    
    					// Read the input in the format: MILES,YARDS,FEET,INCHES
    cin >> m >> comma >> y >> comma >> f >> comma >> i;
    
    
    if (m < 0 || y < 0 || f < 0 || i < 0) 
    {
        d = Distance(0);  
    }
    else 
    {
        d = Distance(m, y, f, i); 
    }

    return is;
}


