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
		while (temp->pnextBook->pnextBook != NULL)
		{
			temp = temp->pnextBook;
		}
		if (temp->pnextBook)
		{
			delete temp->pnextBook;
			temp->pnextBook = NULL;
		}
	}
	delete p0Book;
	Pomesch *temp1;
	while (p0Pom->pnextPom != NULL)
	{
		temp1 = p0Pom;
		while (temp1->pnextPom->pnextPom != NULL)
		{
			temp1 = temp1->pnextPom;
		}
		if (temp1->pnextPom)
		{
			delete temp1->pnextPom;
			temp1->pnextPom = NULL;
		}
	}
	delete p0Pom;
	Kategoriya *temp2;
	while (p0Kat->pnextKat != NULL)
	{
		temp2 = p0Kat;
		while (temp2->pnextKat->pnextKat != NULL)
		{
			temp2 = temp2->pnextKat;
		}
		if (temp2->pnextKat)
		{
			delete temp2->pnextKat;
			temp2->pnextKat = NULL;
		}
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
	if (p0Book->getid() == 0)
	{
		delete p0Book;
		Kniga* c = new Kniga(n, a, 1);
		p0Book = c;
	}
	else{
		Kniga *temp = p0Book;
		while (temp->pnextBook != NULL)
		{
			temp = temp->pnextBook;
		}
		Kniga* c = new Kniga(n, a, temp->getid() + 1);
		temp->pnextBook = c;
		num++;
		return c->getid();
	}
	return 1;
}

int Biblioteka::newKat(string a)
{
	if (p0Kat->getnum() == 0)
	{
		delete p0Kat;
		Kategoriya* c = new Kategoriya(a, 1);
		p0Kat = c;
	}
	else
	{
		Kategoriya *temp = p0Kat;
		while (temp->pnextKat != NULL)
		{
			temp = temp->pnextKat;
		}
		Kategoriya* c = new Kategoriya(a, temp->getnum() + 1);
		temp->pnextKat = c;
		return c->getnum();
	}
	return 1;
}

int Biblioteka::newPom(string a)
{
	if (p0Pom->getid() == 0)
	{
		delete p0Pom;
		Pomesch* c = new Pomesch(a, 1);
		p0Pom = c;
	}
	else
	{
		Pomesch *temp = p0Pom;
		while (temp->pnextPom != NULL)
		{
			temp = temp->pnextPom;
		}
		Pomesch* c = new Pomesch(a, temp->getid() + 1);
		temp->pnextPom = c;
		return c->getid();
	}
	return 1;
}

// Удаление компонента из списка

bool Biblioteka::delBook(int i)
{
	Kniga *temp;
	temp = p0Book;
	if (p0Book->getid() == i)
	{
		temp = p0Book->pnextBook;
		delete p0Book;
		p0Book = temp;
	}
	while (temp->pnextBook != NULL)
	{
		if (temp->pnextBook->getid() == i)
		{
			Kniga *temp2 = temp->pnextBook->pnextBook;
			delete temp->pnextBook;
			temp->pnextBook = temp2;
			num--;
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
	if (p0Kat->getnum() == i)
	{
		temp = p0Kat->pnextKat;
		delete p0Kat;
		p0Kat = temp;
	}
	while (temp->pnextKat != NULL)
	{
		if (temp->pnextKat->getnum() == i)
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
	if (p0Pom->getid() == i)
	{
		temp = p0Pom->pnextPom;
		delete p0Pom;
		p0Pom = temp;
	}
	while (temp->pnextPom != NULL)
	{
		if (temp->pnextPom->getid() == i)
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

Pomesch* Biblioteka::PomByid(int a)
{
	Pomesch *temp;
	temp = p0Pom;
	while (temp != NULL)
	{
		if (temp->getid() == a)
		{
			return temp;
		}
		temp = temp->pnextPom;
	}
	return NULL;
}

bool Biblioteka::obedPom(int id1, int id2)
{
	*PomByid(id1) = (*PomByid(id1) + *PomByid(id2));
	Kniga *temp;
	int k = 0;
	temp = p0Book;
	while (temp != NULL)
	{
		if (temp->getidPom() == id2)
		{
			temp->newPomid(id1);
		}
		temp = temp->pnextBook;
	}
	delPom(id2);
	return 1;
}

Kniga* Biblioteka::BookByid(int a)
{
	Kniga *temp;
	temp = p0Book;
	while (temp != NULL)
	{
		if (temp->getid() == a)
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
	while (temp != NULL)
	{
		if (a == temp->getname() || a == temp->getauthor())
		{
			k++;
			cout << "id " << temp->getid() << " " << temp->getauthor() << " \"" << temp->getname() << "\"" << endl;
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
	while (temp != NULL)
	{
		cout << "id " << temp->getid() << " " << temp->getauthor() << " \"" << temp->getname() << "\"" << endl;
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
		while (temp != NULL)
		{
			if (temp->getidPom() == t)
			{
				k++;
				cout << "id " << temp->getid() << " " << temp->getauthor() << " \"" << temp->getname() << "\"" << endl;
			}
			temp = temp->pnextBook;
		}
		cout << "Найдено " << k << "книг" << endl;
	}
	else if (a == 'k' || a == 'K')
	{
		while (temp != NULL)
		{
			for (int i = 0; i < temp->getnumKat(); i++)
			{
				if (temp->getidKat()[i] == t)
				{
					k++;
					cout << "id " << temp->getid() << " " << temp->getauthor() << " \"" << temp->getname() << "\"" << endl;
				}
			}
			temp = temp->pnextBook;
		}
		cout << "Найдено " << k << "книг" << endl;
	}
	else cout << "Неправильный индентификатор (p/k)" << endl;
	return 1;
}