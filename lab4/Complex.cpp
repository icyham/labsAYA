#include "StdAfx.h"
#include "Complex.h"


Complex::Complex(void)
{
	re = 0;
	im = 0;
}
Complex::Complex(double r) // конструктор по умолчанию
{
	re = r;
	im = 0;
}

Complex::Complex(double r, double i) // конструктор по умолчанию
{
	re = r;
	im = i;
}

Complex::Complex(Complex &c) // конструктор копирования
{
	re = c.re;
	im = c.im;
}

Complex::~Complex(void)
{
}

Complex & Complex::operator = (Complex &c)
{
	re = c.re;
	im = c.im;

	return (*this);
}

Complex Complex::operator + (Complex &c)
{
	Complex temp;

	temp.re = re + c.re;
	temp.im = im + c.im;

	return temp;
}

Complex Complex::operator - (Complex &c)
{
	Complex temp;

	temp.re = re - c.re;
	temp.im = im - c.re;

	return temp;
}

Complex Complex::operator * (Complex &c)
{
	Complex temp;

	temp.re = re*c.re-im*c.im;
	temp.im = re*c.im+im*c.re;

	return temp;
}



ostream &operator<<(ostream &out, Complex &c)
{
	out << "(" << c.re << ") + I (" << c.im << ")";

	return out;
}

istream &operator>>(istream &in, Complex &c)
{
	in >> c.re >> c.im;

	return in;
}

