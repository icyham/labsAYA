/*�������� :

��������� �����
����� �����
���������� �����(���� ����������)
�������� ������� ��������
����������� ����� ����� �����������
����������, �����������, ���������� ���������
������� ������� �������� ��� ������*/

#include"stdafx.h"
#include"Biblioteka.h"

void startuse()
{
	Biblioteka b;
	cout << "��� ������ �������� esc\n��� ��������� ������� �������� help"<<endl;
	string command;
	while (command.compare(0, 3, "esc"))
	{
		cin >> command;
		if (!command.compare(0, 4, "help")) {
			cout << "\n�������� ����� - addbook name author\n������� ����� - delbook id\n����� ����� - find name/author\n�������� ��������� - addkat name\n������� ��������� - delkat id\n�������� ��������� - addpom name\n������� ��������� - delpom id\n���������� ��������� - obedpom id1 id2\n������ ���� - list\n����� ��������� - listk idk\n����� � ��������� - listp idp\n���������� ����� - ocifr id\n������� ������������ ����� - download id\n����������� ����� � ��������� - booktopom idb idp\n�������� ����� ��������� - bookaddkat idb idk\n������� � ����� ��������� - bookdelkat idb idk\n������� ����� - hist id"<<endl;
		}
		if (!command.compare(0, 7, "addbook")) {
			string n, a;
			cin >> n >> a;

			b.newBook(n, a);
		}
		if (!command.compare(0, 7, "delbook")) {
			int id;
			cin >> id;
			b.delBook(id);
		}
		if (!command.compare(0, 4, "find")) {
			string n;
			cin >> n;
			b.Poisk(n);
		}
		if (!command.compare(0, 6, "addkat")) {
			string n;
			cin >> n;
			b.newKat(n);
		}
		if (!command.compare(0, 6, "delkat")) {
			int id;
			cin >> id;
			b.delKat(id);
		}
		if (!command.compare(0, 6, "addpom")) {
			string n;
			cin >> n;
			b.newPom(n);
		}
		if (!command.compare(0, 6, "delpom")) {
			int id;
			cin >> id;
			b.delPom(id);
		}
		if (!command.compare(0, 7, "obedpom")) {
			int id1, id2;
			cin >> id1 >> id2;
			b.obedPom(id1, id2);
		}
		if (!command.compare(0, 4, "list")) {
			b.List();
		}
		if (!command.compare(0, 5, "listk")) {
			int id;
			cin >> id;
			b.List('k', id);
		}
		if (!command.compare(0, 5, "listp")) {
			int id;
			cin >> id;
			b.List('p', id);
		}
		if (!command.compare(0, 5, "ocifr")) {
			int id;
			cin >> id;
			b.BookByid(id)->doOcifr();
		}
		if (!command.compare(0, 8, "download")) {
			int id;
			cin >> id;
			b.BookByid(id)->download();
		}
		if (!command.compare(0, 9, "booktopom")) {
			int idb, idp;
			cin >> idb >> idp;
			b.BookByid(idb)->newPomid(idp);
		}
		if (!command.compare(0, 10, "bookaddkat")) {
			int idb, idk;
			cin >> idb >> idk;
			b.BookByid(idb)->addKat(idk);
		}
		if (!command.compare(0, 10, "bookdelkat")) {
			int idb, idk;
			cin >> idb >> idk;
			b.BookByid(idb)->delKat(idk);
		}
		if (!command.compare(0, 4, "hist")) {
			int idb;
			cin >> idb;
			cout << b.BookByid(idb)->gethist();
		}
	}
}