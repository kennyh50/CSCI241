/*********************************************************************
   PROGRAM:    Complex.cpp
   PROGRAMMER: Kenneth Harris
   LOGON ID:   z1733721
   DUE DATE:   10/23/18

   FUNCTION:   This program contains the methods for the Complex class.
*********************************************************************/

#include "Complex.h"
#include <iostream>
#include <iomanip>
using namespace std;
using std::ostream;
using std::istream;

//This method assigns the method parameters to the corresponding data members.
Complex::Complex(double newReal ,double newImaginary)
{
realPart = newReal;
imaginary = newImaginary;
}

//This method assigns the parameters to the data members.
void Complex::setComplex(double rp, double ip)
{
realPart = rp;
imaginary = ip;
}

//This method assigns the data members to the method parameters.
//It passes back the value of both parts of the complex number with one call.
void Complex::getComplex(double& realComplex, double& imaginaryComplex) const
{
realComplex = this -> realPart;
imaginaryComplex = this -> imaginary;
}

//Assigns the method parameter to the realPart data member.
void Complex::setRealPart(double newRealPart)
{
realPart = newRealPart;
}

//This method Returns the data member representing the real part of the complex number.
double Complex::getRealPart() const
{
return realPart;
}

//Assigns the method parameter to the realPart data member.
void Complex::setImaginaryPart(double newImaginary)
{
imaginary = newImaginary;
}

//This method returns the data member representing the imaginary part of the complex number.
double Complex::getImaginaryPart() const
{
return imaginary;
}

//This method overloads the + operator so that it does the necessarry math.
Complex Complex::operator+(const Complex& rhs) const
{
Complex result = *this;

result.realPart = realPart + rhs.realPart;
result.imaginary = imaginary + rhs.imaginary;

return result;
}

//This method overloads the * operator so that it can do the necessarry math.
Complex Complex::operator*(const Complex& rhs) const
{
Complex result = *this;

result.realPart = realPart*rhs.realPart - imaginary*rhs.imaginary;
result.imaginary = realPart*rhs.imaginary + imaginary*rhs.realPart;

return result;
}

//This method overloads the == operator to check to see if both operands are equal.
bool Complex::operator==(const Complex& rhs) const
{
return (realPart == rhs.realPart && imaginary == rhs.imaginary);
}

//This function overloads the << operator so that it can output the proper characters.
ostream& operator << (ostream& lhs, const Complex& rhs)
{
lhs <<'(' << rhs.realPart << ',' << rhs.imaginary << ')' << endl;
return lhs;
}

//This funcion overloads the << operator so that it only reads in the characters that we need. 
istream& operator >> (istream& lhs, Complex& rhs)
{
char ch;
lhs >> ch;
lhs >> rhs.realPart;
lhs >> ch;
lhs >> rhs.imaginary;
lhs >> ch;

return lhs;
}

