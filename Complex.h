#pragma once
class Complex
{
	double re, im; // целая и мнимая части
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
 
   friend ostream &operator<<(ostream &, Complex &); // перегрузка оператора <<
   friend istream &operator>>(istream &, Complex &); // перегрузка оператора >>
 
};

