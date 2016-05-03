#pragma once
/*Процессы :

		 оцифровка книги
		 поиск книги
		 скачивание книги(если оцифрована)
		 просмотр раздела каталога
		 перемещение книги между помещениями
		 добавление, объединение, разделение помещений
		 ведение история операций над книгой*/

class Kniga
{
	string name;
	string author;
	int id;
	int idPom;
	int numKat;
	int* idKat;
	bool ocifr;
	
public:
	Kniga* pnextBook;
	Kniga();
	~Kniga();
	Kniga & operator = (Kniga &t)
	{
		name = t.name;
		author = t.author;
		id = t.id;
		idPom = t.idPom;
		idKat = t.idKat;
		ocifr = t.ocifr;
		pnextBook = t.pnextBook;
		return (*this);
	}
	int getid()
	{
		return id;
	}
	string getname()
	{
		return name;
	}
	string getauthor()
	{
		return author;
	}
	int getidPom()
	{
		return idPom;
	}
	int getnumKat()
	{
		return numKat;
	}
	int* getidKat()
	{
		return idKat;
	}
	bool doOcifr();
	bool download();
	bool newPomid(int);
};

