#ifndef COMPLEX__H
#define COMPLEX__H
#include <iostream>
using std::ostream;
using std::istream;
using namespace std;

   //*****************************************************************
   // FILE:      Complex.h
   // AUTHOR:    Kenneth Harris
   // LOGON ID:  z1733721
   // DUE DATE:  10/23/2018
   //
   // PURPOSE:   Contains the declaration for the Complex class.
   //*****************************************************************/

   class Complex
      {
        private:
                double realPart;
                double imaginary;

        public:
                Complex(double=0 ,double=0);
                void setComplex(double rp, double ip);
                void getComplex(double& realComplex, double& imaginaryComplex) const;
                void setRealPart(double newRealPart);
                double getRealPart() const;
                void setImaginaryPart(double newImaginary);
                double getImaginaryPart() const;
                Complex operator+(const Complex& rhs) const;
                Complex operator*(const Complex& rhs) const;
                bool operator==(const Complex& rhs) const;
		friend ostream& operator << (ostream& lhs, const Complex& rhs);
		friend istream& operator >> (istream& lhs,  Complex& rhs);

      };

   #endif

