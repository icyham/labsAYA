#pragma once
#include "Complex.h"
//Матрицы: умножение, сложение, транспонирование, получение по индексу
class Matrixx
{
	int row, col; //столбцы строчки
	int del;
public:
	Complex* data;
	Matrixx(void);
	Matrixx(int row);
	Matrixx(int row, int col);
	~Matrixx(void);

	int getrow(Matrixx);
	int getcol(Matrixx);
	Matrixx & operator = (Matrixx &c);
	Matrixx operator + (Matrixx &c);
	Matrixx operator * (Matrixx &c);
	friend Complex& Matrindex(Matrixx& t, int i, int j);
//	friend Matrixx & operator ~(Matrixx &t);
	friend ostream &operator<<(ostream &out, Matrixx &c);
	friend istream &operator>>(istream &in, Matrixx &c);
};

