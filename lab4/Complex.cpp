#include "StdAfx.h"
#include "Complex.h"


Complex::Complex(void)
{
	re = 0;
	im = 0;
}
Complex::Complex(double r) // конструктор по умолчанию -- это конструктор преобразования
{
	re = r;
	im = 0;
}

Complex::Complex(double r, double i) // конструктор по умолчанию -- это конструктор с параметрами
{
	re = r;
	im = i;
}

// такой конструктор генерируется автоматически
Complex::Complex(Complex &c) // конструктор копирования // const reference
{
	re = c.re;
	im = c.im;
}

// такой деструктор генерируется автоматически
Complex::~Complex(void)
{
}
// такой оператор присваивания генерируется автоматически
Complex & Complex::operator = (Complex &c) // параметр -- константная ссылка
{
	re = c.re;
	im = c.im;

	return (*this);
}

// этот метод константный
Complex Complex::operator + (Complex &c) // параметр -- константная ссылка
{
	Complex temp;

	temp.re = re + c.re;
	temp.im = im + c.im;

	return temp;
}

// этот метод константный
Complex Complex::operator - (Complex &c) // параметр -- константная ссылка
{
	Complex temp;

	temp.re = re - c.re;
	temp.im = im - c.re;

	return temp;
}

//
Complex Complex::operator * (Complex &c) //
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

// ввод не соответствует выводу
istream &operator>>(istream &in, Complex &c)
{
	in >> c.re >> c.im;

	return in;
}

