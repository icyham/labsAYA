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
	int* idKat;
	bool ocifr;
	Kniga* pnextK;
public:
	Kniga();
	~Kniga();
	bool doOcifr(Kniga &book);

};

