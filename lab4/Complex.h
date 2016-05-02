#pragma once
class Complex
{
	double re, im; //Целая и мнимая части
public:
	Complex(void);
	Complex (double r) ;
	Complex (double r, double i) ;
	Complex (Complex &c) ;
	~Complex();
 
   Complex & operator = (Complex &c);
 
   Complex operator + (Complex &c);
 
   Complex operator - (Complex &c);
 
   Complex operator * (Complex &c);
 
   Complex operator / (Complex &c);
 
   friend ostream &operator<<(ostream &, Complex &); 
   friend istream &operator>>(istream &, Complex &); 
 
};

