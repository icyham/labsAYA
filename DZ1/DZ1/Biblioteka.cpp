#include "stdafx.h"
#include "Biblioteka.h"


Biblioteka::Biblioteka()
{

}


Biblioteka::~Biblioteka()
{
}

Biblioteka & Biblioteka::operator = (Biblioteka &t)
{
	p0Book = t.p0Book;
	p0Pom = t.p0Pom;
	p0Kat = t.p0Kat;
	num = t.num;
	return (*this);
}

bool Biblioteka::Poisk(string)
{
	Kniga *temp = new Kniga;
	int k = 0;
	temp = p0Book;
	while (temp->pnextBook != NULL)
	{
		if (1)//string == name || author
		{
			k++;
			cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
		}
		temp = temp->pnextBook;
	}
	cout << "Naydeno " << k << "rezultatov" << endl;
	delete temp;
	return 1;
}


bool Biblioteka::List()
{
	Kniga *temp = new Kniga;
	temp = p0Book;
	cout << "Vsego " << num << "knig" << endl;
	while (temp->pnextBook != NULL)
	{
		cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
		temp = temp->pnextBook;
	}
	delete temp;
	return 1;
}

bool Biblioteka::List(char a, int t)
{
	Kniga *temp = new Kniga;
	int k = 0;
	temp = p0Book;
	if (a == 'p' || a == 'P')
	{
		while (temp->pnextBook != NULL)
		{
			if (temp->getidPom == t)
			{
				k++;
				cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
			}
			temp = temp->pnextBook;
		}
		cout << "Vsego naydeno " << k << "knig" << endl;
	}
	else if (a == 'k' || a == 'K')
	{
		while (temp->pnextBook != NULL)
		{
			for (int i = 0; i < temp->getnumKat(); i++)
			{
				if (temp->getidKat()[i] == t)
				{
					k++;
					cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
				}
			}
			temp = temp->pnextBook;
		}
		cout << "Vsego naydeno " << k << "knig" << endl;
	}
	else cout << "Nepravilniy indentificator" << endl;
	delete temp;
	return 1;
}