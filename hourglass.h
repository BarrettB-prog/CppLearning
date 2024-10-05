#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Hourglass
{
   public:
    Hourglass();                // when run without params, will set to defualt values seen below. Set in .cpp file
    Hourglass(int S = 1, char BC = '#', char FC = '*');     // S = size of hourglass, BC = BorderChar, FC = FillChar
    
    void Draw() const;
    
    void SetSize(int Size);
    void SetBorder(char BorderChar);
    void SetFill(char FillChar);
    
    int GetSize() const;        //return Size
    int GetPerimeter() const;   //idk what this does
    double GetArea() const;     // size x size = Area. return that
    
    int Grow();
    int Shrink;
    
    void Summary() const;

   private:
    int Size;      //triangles involved are equilatateral so only 1 side length is needed
    char BorderChar;
    char FillChar;
    
};