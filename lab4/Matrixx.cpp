#include "StdAfx.h"
#include "Matrixx.h"


Matrixx::Matrixx(void)
{
	data = NULL;
	row = 0;
	col = 0;
	del = 0; // это какой-то мерзкий хак, которого быть не должно
}
Matrixx::Matrixx(int x) //квадратная матрица // uint maybe?
{
	Complex a(0);
	data = new Complex[x*x];
	row = x;
	col = x;
	del = 0;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			data[i*col + j] = a;
		}
	}
}
Matrixx::Matrixx(int x, int y) //  строчки и столбцы
{
	Complex a(0);
	data = new Complex[x*y];
	row = x;
	col = y;
	del = 0;
	// этот цикл не нужен
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			data[i*col + j] = a; // конструктор по умолчанию для complex и так инициализирует нулем
		}
	}
}
Matrixx::~Matrixx(void)
{
	if(Matrixx::del==0) delete []data;
	else del = 0;
}

int Matrixx::getrow(Matrixx t) // что за параметр? может, объект будет возвращать свое количество строк, а не чужое?
{
	return t.row;
}
int Matrixx::getcol(Matrixx t) // ...
{
	return t.col;
}

Matrixx Matrixx::operator + (Matrixx &c) // const, const
{
	Matrixx temp(row, col);
	temp.del = 1; // этот мерзкий хак сделан, потому что не был сделан конструктор копирования
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			temp.data[i*col + j] = data[i*col + j] + c.data[i*col + j];
		}
	}
	return temp;
}
Matrixx Matrixx::operator * (Matrixx &c) // const, const
{
	// все ли матрицы можно перемножать?
	Matrixx temp(row, c.col);
	temp.del = 1;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<c.col; j++)
		{
			for (int k = 0; k<col; k++)
			{
				temp.data[c.col*i + j] = temp.data[c.col*i + j] + data[col*i + k] * c.data[c.col*k + j];
			}
		}
	}
	return temp;
}
Matrixx & Matrixx::operator = (Matrixx &c)
{
	delete []data;
	col = c.col;
	row = c.row;
	data = new Complex[col*row];
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			data[i*col + j] = c.data[i*col + j];
		}
	}
	return (*this);
}
/*Matrixx & operator ~(Matrixx &t)
{
	Matrixx temp(t.col, t.row);
	temp.del = 1;
	for (int i = 0; i<t.col; i++)
	{
		for (int j = 0; j<t.row; j++)
		{
			temp.data[t.col*i + j] = t.data[j*t.row + i];
		}
	}
	return temp;
}*///выдает ошибку в ассемблере

Complex& Matrindex(Matrixx& t, int i, int j) // что за параметр? может, объект будет возвращать свои данные, а не чужие?
{
	return t.data[i*t.col + j];

}

ostream &operator<<(ostream &out, Matrixx &c)
{
	for (int i = 0; i<c.row; i++)
	{
		for (int j = 0; j<c.col; j++)
		{
			out << c.data[i*c.col + j] << " ";
		}
		out << "\n";
	}
	return out;
}

istream &operator>>(istream &in, Matrixx &c)
{
	for (int i = 0; i<c.row; i++)
	{
		for (int j = 0; j<c.col; j++)
		{
			in >> c.data[i*c.col + j];
		}
	}
	return in;
}
