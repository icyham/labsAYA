#include "stdafx.h"
#include "Biblioteka.h"


Biblioteka::Biblioteka()
{
	p0Book = new Kniga();
	p0Pom = new Pomesch();
	p0Kat = new Kategoriya();
	num = 1;
}


Biblioteka::~Biblioteka()
{
	Kniga *temp;
	while (p0Book->pnextBook != NULL)
	{
		temp = p0Book;
		while (temp->pnextBook != NULL)
		{
			temp = temp->pnextBook;
		}
		delete temp;
	}
	delete p0Book;
	Pomesch *temp1;
	while (p0Pom->pnextPom != NULL)
	{
		temp1 = p0Pom;
		while (temp1->pnextPom != NULL)
		{
			temp1 = temp1->pnextPom;
		}
		delete temp1;
	}
	delete p0Pom;
	Kategoriya *temp2;
	while (p0Kat->pnextKat != NULL)
	{
		temp2 = p0Kat;
		while (temp2->pnextKat != NULL)
		{
			temp2 = temp2->pnextKat;
		}
		delete temp2;
	}
	delete p0Kat;
}

Biblioteka & Biblioteka::operator = (Biblioteka &t)
{
	p0Book = t.p0Book;
	p0Pom = t.p0Pom;
	p0Kat = t.p0Kat;
	num = t.num;
	return (*this);
}

// Включение в список нового компонента
int Biblioteka::newBook(string n, string a)
{
	Kniga *temp = p0Book;
	while (p0Book->pnextBook != NULL)
	{
		temp = temp->pnextBook;
	}
	Kniga* c = new Kniga(n, a, temp->getid+1);
	temp->pnextBook = c;
	return c->getid;
}

int Biblioteka::newKat(string a)
{
	Kategoriya *temp = p0Kat;
	while (p0Kat->pnextKat != NULL)
	{
		temp = temp->pnextKat;
	}
	Kategoriya* c = new Kategoriya(a, temp->getnum + 1);
	temp->pnextKat = c;
	return c->getnum;
}

int Biblioteka::newPom(string a)
{
	Pomesch *temp = p0Pom;
	while (p0Pom->pnextPom != NULL)
	{
		temp = temp->pnextPom;
	}
	Pomesch* c = new Pomesch(a, temp->getid + 1);
	temp->pnextPom = c;
	return c->getid;
}

// Удаление компонента из списка

bool Biblioteka::delBook(int i)
{
	Kniga *temp;
	temp = p0Book;
	if (p0Book->getid == i)
	{
		temp = p0Book->pnextBook;
		delete p0Book;
		p0Book = temp;
	}
	while (temp->pnextBook != NULL)
	{
		if (temp->pnextBook->getid == i)
		{
			Kniga *temp2 = temp->pnextBook->pnextBook;
			delete temp->pnextBook;
			temp->pnextBook = temp2;
			return 1;
		}
		temp = temp->pnextBook;
	}
	return 0;
}

bool Biblioteka::delKat(int i)
{
	Kategoriya *temp;
	temp = p0Kat;
	if (p0Kat->getnum == i)
	{
		temp = p0Kat->pnextKat;
		delete p0Kat;
		p0Kat = temp;
	}
	while (temp->pnextKat != NULL)
	{
		if (temp->pnextKat->getnum == i)
		{
			Kategoriya *temp2 = temp->pnextKat->pnextKat;
			delete temp->pnextKat;
			temp->pnextKat = temp2;
			return 1;
		}
		temp = temp->pnextKat;
	}
	return 0;
}

bool Biblioteka::delPom(int i)
{
	Pomesch *temp;
	temp = p0Pom;
	if (p0Pom->getid == i)
	{
		temp = p0Pom->pnextPom;
		delete p0Pom;
		p0Pom = temp;
	}
	while (temp->pnextPom != NULL)
	{
		if (temp->pnextPom->getid == i)
		{
			Pomesch *temp2 = temp->pnextPom->pnextPom;
			delete temp->pnextPom;
			temp->pnextPom = temp2;
			return 1;
		}
		temp = temp->pnextPom;
	}
	return 0;
}

Kniga* Biblioteka::BookByid(int a)
{
	Kniga *temp;
	temp = p0Book;
	while (temp->pnextBook != NULL)
	{
		if (temp->getid == a)
		{
			return temp;
		}
		temp = temp->pnextBook;
	}
	return NULL;
}

bool Biblioteka::Poisk(string a)
{
	Kniga *temp;
	int k = 0;
	temp = p0Book;
	while (temp->pnextBook != NULL)
	{
		if (a==temp->getname || a==temp->getauthor)//string == name || author
		{
			k++;
			cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
		}
		temp = temp->pnextBook;
	}
	cout << "Найдено " << k << "результатов." << endl;
	return 1;
}


bool Biblioteka::List()
{
	Kniga *temp;
	temp = p0Book;
	cout << "Всего " << num << "книг" << endl;
	while (temp->pnextBook != NULL)
	{
		cout << "id " << temp->getid << " " << temp->getauthor << " \"" << temp->getname << "\"" << endl;
		temp = temp->pnextBook;
	}
	return 1;
}

bool Biblioteka::List(char a, int t)
{
	Kniga *temp;
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
		cout << "Найдено " << k << "книг" << endl;
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
		cout << "Найдено " << k << "книг" << endl;
	}
	else cout << "Неправильный индентификатор (p/k)" << endl;
	return 1;
}