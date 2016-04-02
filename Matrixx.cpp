#include "StdAfx.h"
#include "Matrixx.h"


Matrixx::Matrixx(void)
{
	data = NULL;
	row = 0;
	col = 0;
}
Matrixx::Matrixx(int x) //квадратная матрица
{
	data = new double[x*x];
	row = x;
	col = x;
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
		data[i*col+j] = 0;
		}
	}
}
Matrixx::Matrixx(int x, int y) //  строчки и столбцы
{
	data = new double[x*y];
	row = x;
	col = y;
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
		data[i*col+j] = 0;
		}
	}
}
Matrixx::~Matrixx(void)
{
	delete data;
}

int Matrixx::getrow(Matrixx t)
{
	return t.row;
}
int Matrixx::getcol(Matrixx t)
{
	return t.col;
}
int Matrixx::printmat(Matrixx t)
{
	for (int i=0; i<t.row; i++)
	{
		for (int j=0; j<t.col; j++)
		{
			cout<<t.data[i*t.col+j]<<" ";
		}
		cout<<endl;
	}
	return 1;
}
Matrixx Matrixx::operator + (Matrixx &c)
{
	Matrixx temp(row, col);
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
	temp.data[i*col+j] = data[i*col+j]+c.data[i+col+j];
		}
	}
    return temp;
}
Matrixx Matrixx::operator * (Matrixx &c)
{
	Matrixx temp(row, c.col);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<c.col; j++)
		{
			for(int k=0; k<col; k++)
			{
				temp.data[c.col*i+j]+=data[col*i+k]*c.data[c.col*k+j];
			}
		}
	}
	return temp;
}
Matrixx & Matrixx::operator = (Matrixx &c)
   {
	   delete data;
       col = c.col;
       row = c.row;
	   data = new double[col*row];
	   for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				data[i*col+j] = c.data[i*col+j];
			}
		}
      return (*this);
   }
Matrixx & operator ~(Matrixx &t)
{
	Matrixx temp(t.col, t.row);
	for(int i=0; i<t.col; i++)
	{
		for(int j=0; j<t.row; j++)
		{
			temp.data[t.row*i+j]=t.data[t.col*j+i];
		}
	}
	
	return temp;
}
double Matrixx::Matrindex (Matrixx t, int i, int j)
{
		return data[i*col+j];
}
