// laba4.cpp : Defines the entry point for the console application.
//Вариант 25 Комплексное 
//Матрицы: умножение, сложение, транспонирование, получение по индексу

#include "stdafx.h"
#include "Complex.h"
#include "Matrixx.h"

int main()
{

	Complex value1(5, 2);
	Complex value2(3, -3);
	cout << "First num:" << value1 << "\n" << "Second num:" << value2 << endl;
	cout << "Plus: " << value1 + value2 << endl;
	cout << "Minus: " << value1 - value2 << endl;
	cout << "Multiplication: " << value1 * value2 << endl;
	value1 = value2;
	cout << "Assimilation: " << value1 << " = " << value2 << endl;

	cout << "\n\n";
	
	Matrixx matr1(2, 3);
	for (int i = 0; i < 6; i++)
	{
		Complex temp(rand() % 20, rand() % 10);
		matr1.data[i] = temp;
	}
	Matrixx matr2(3, 4);
	for (int i = 0; i < 12; i++)
	{
		Complex temp(rand() % 20, rand() % 10);
		matr2.data[i] = temp;
	}
	
	Matrixx matr3(2, 3);
	for (int i = 0; i < 6; i++)
	{
		Complex temp(rand() % 20, rand() % 10);
		matr3.data[i] = temp;
	}
	cout << "matr1: \n" << matr1 << "matr2: \n" << matr2 << "matr3: \n" << matr3 << endl;
	cout << "matr1+matr3: \n" << (matr1+matr3) << endl;
	cout << "matr1*matr2: \n" << matr1*matr2 << endl;
	//cout << ~matr1 << endl;
	cout << "matr1: \n" << matr1 << "matr2: \n" << matr2 << "matr3: \n" << matr3 << endl;
	cout << "matr1(1,1) = " << Matrindex(matr1, 1, 1) << endl;
	//Запись в файл при использовании потоков
	ofstream out("text.txt", ios::app);
	if (!out)
	{
		cout << "Create a file first \n";
		system("pause");
		return 0;
	}
	out << matr1 << endl;
	out.close();
	system("pause");
	return 0;
}
