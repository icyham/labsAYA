#pragma once
/*Процессы :

оцифровка книги
поиск книги
скачивание книги(если оцифрована)
просмотр раздела каталога
перемещение книги между помещениями
добавление, объединение, разделение помещений
ведение история операций над книгой*/

#include "Kniga.h"
#include "Pomesch.h"
#include "Kategoriya.h"
class Biblioteka
{
	Kniga * p0Book;
	Pomesch * p0Pom;
	Kategoriya * p0Kat;
	int num;//колво книг
public:
	Biblioteka();
	~Biblioteka();
	Biblioteka & operator = (Biblioteka &t);
	int newBook(string, string);
	int newKat(string);
	int newPom(string);
	bool delBook(int);
	bool delKat(int);
	bool delPom(int);
	Kniga* BookByid(int);
	bool Poisk(string);
	bool List();
	bool List(char, int);
};

