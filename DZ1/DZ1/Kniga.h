#pragma once
/*�������� :

		 ��������� �����
		 ����� �����
		 ���������� �����(���� ����������)
		 �������� ������� ��������
		 ����������� ����� ����� �����������
		 ����������, �����������, ���������� ���������
		 ������� ������� �������� ��� ������*/

class Kniga
{
	string name;
	string author;
	int id;
	int idPom;
	int* idKat;
	bool ocifr;
	Kniga* pnextK;
public:
	Kniga();
	~Kniga();
	bool doOcifr(Kniga &book);

};

