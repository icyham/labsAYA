// laba4.cpp : Defines the entry point for the console application.
//Вариант 25 Комплексное 
//Матрицы: умножение, сложение, транспонирование, получение по индексу

#include "stdafx.h"
#include "Complex.h"
#include "Matrixx.h"

int main()
{
	
    Complex value1(5,2);
    Complex value2(3,-3);
    cout << "First num:" << value1 << "\n" << "Second num:" << value2 << endl;
    cout << "Plus: " << value1 + value2 << endl;
    cout << "Minus: " << value1 - value2 << endl;
    cout << "Multiplication: " << value1 * value2 << endl;
    cout << "Division: " << value1 / value2 << endl;    
    value1 = value2;
    cout << "Assimilation: " << value1 << " = " << value2 << endl;

	cout << "\n\n";

	Matrixx matr1(2, 3);
	matr1.data[0]=1;
	matr1.data[1]=3;
	matr1.data[2]=2;
	matr1.data[3]=0;
	matr1.data[4]=4;
	matr1.data[5]=-1;
	Matrixx matr2(3, 4);
	matr2.data[0]=2;
	matr2.data[1]=0;
	matr2.data[2]=-1;
	matr2.data[3]=1;
	matr2.data[4]=3;
	matr2.data[5]=-2;
	matr2.data[6]=1;
	matr2.data[7]=2;
	matr2.data[8]=0;
	matr2.data[9]=1;
	matr2.data[10]=2;
	matr2.data[11]=3;
	Matrixx::printmat(matr1);
	cout<<"\n";
	Matrixx::printmat(matr2);
	//Matrixx::printmat(matr1+matr2);
	
	
	system("pause");
    return 0;
}