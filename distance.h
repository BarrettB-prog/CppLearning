#include <iostream>
using namespace std;

class Distance
{
public:
    
    Distance();
    Distance(int totalInches);                  // Conversion constructor
    Distance(int m, int y, int f, int i);

    // Overload arithmetic operators
    Distance operator+(const Distance& other) const;
    Distance operator-(const Distance& other) const;
    Distance operator*(int multiplier) const;

    // overload comparison operators
    bool operator<(const Distance& other) const;
    bool operator>(const Distance& other) const;
    bool operator<=(const Distance& other) const;
    bool operator>=(const Distance& other) const;
    bool operator==(const Distance& other) const;
    bool operator!=(const Distance& other) const;

    // Overload increment and decrement operators
    Distance& operator++();    // Pre-increment
    Distance operator++(int);  // Post-increment
    Distance& operator--();    // Pre-decrement
    Distance operator--(int);  // Post-decrement

    // Overload I/O stream operators
    friend ostream& operator<<(ostream& os, const Distance& d);
    friend istream& operator>>(istream& is, Distance& d);

    
private:
    int miles;
    int yards;
    int feet;
    int inches;

    // Helper function to simplify distance
    void simplify();    
    
};

