#pragma once
/*�������� :

��������� �����
����� �����
���������� �����(���� ����������)
�������� ������� ��������
����������� ����� ����� �����������
����������, �����������, ���������� ���������
������� ������� �������� ��� ������*/

#include "Kniga.h"
#include "Pomesch.h"
#include "Kategoriya.h"
class Biblioteka
{
	Kniga * p0Book;
	Pomesch * p0Pom;
	Kategoriya * p0Kat;
	int num;//����� ����
public:
	Biblioteka();
	~Biblioteka();
	Biblioteka & operator = (Biblioteka &t);
	bool Poisk(string);
	bool List();
	bool List(char, int);
};

