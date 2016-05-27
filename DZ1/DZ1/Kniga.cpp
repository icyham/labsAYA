#include "stdafx.h"
#include "Kniga.h"


Kniga::Kniga()
{
	name = "NULL";
	author = "NULL";
	id=0;
	idPom=0;
	numKat=0;
	idKat=NULL;
	ocifr=0;
	pnextBook = NULL;
	hist = "����..����� ��������� � �������\n";
}
Kniga::Kniga(string n, string a)
{
	name = n;
	author = a;
	id = 0;
	idPom = 0;
	numKat = 1;
	idKat = new int[1];
	idKat[0] = 0;
	ocifr = 0;
	pnextBook = NULL;
	hist = "����� ��������� � �������: id = 0 " + a + " " + n + "\n";
}

Kniga::Kniga(string n, string a, int i)
{
	name = n;
	author = a;
	id = i;
	idPom = 0;
	numKat = 1;
	idKat = new int[1];
	idKat[0] = 0;
	ocifr = 0;
	pnextBook = NULL;
	hist = "����� ��������� � �������: id = " + to_string(i) + " " + a + " " + n + "\n";
}

Kniga::~Kniga()
{
	//delete[] idKat;
}

bool Kniga::doOcifr()
{
	if (this->ocifr == 1) return 0; 
	this->ocifr = 1;
	hist += "����� ���� ����������\n";
	return 1;
}
bool Kniga::download()
{
	if (this->ocifr == 1)
	{
		cout << "��������� �����... (���)" << endl;
		hist += "����� ���� �������\n";
		return 1;
	}
	else
	{
		cout << "����� �� ����������, ���������� �������" << endl;
		return 0;
	}
}
bool Kniga::newPomid(int a)
{
	this->idPom = a;
	hist = "����� ���������� � ���������: id = " + to_string(a) + "\n";
	return 1;
}
bool Kniga::addKat(int a)
{
	int i;
	for (i = 0; i < this->numKat; i++)
	{
		if (this->idKat[i] == a)
		{
			cout << "����� ��� ����� ��� ���������." << endl;
			return 0;
		}
	}
	int* t = new int[this->numKat++];
	for (i = 0; i < this->numKat-1; i++)
	{
		t[i] = this->idKat[i];
	}
	t[i] = a;
	delete[] this->idKat;
	this->idKat = t;
	hist = "����� ��������� � ���������: id = " + to_string(a) + "\n";
	return 1;
}
bool Kniga::delKat(int a)
{
	int i;
	for (i = 0; i < this->numKat; i++)
	{
		if (this->idKat[i] == a)
		{
			int* t = new int[this->numKat--];
			for (int j = 0; j < i; j++)
			{
				t[j] = this->idKat[j];
			}
			for (int j = i+1; j < this->numKat+1; j++)
			{
				t[j-1] = this->idKat[j];
			}
			delete[] this->idKat;
			this->idKat = t;
			hist = "����� ������� �� ���������: id = " + to_string(a) + "\n";
			return 1;
		}
	}
	cout << "�� ������� ����� ���������" << endl;
	return 0;

}

string Kniga::gethist()
{
	return this->hist;
}

ostream &operator<<(ostream &out, Kniga &c)
{
	out << "id: " << c.id << " " << c.author << " - " << c.name << "\n" << c.hist;
	return out;
}