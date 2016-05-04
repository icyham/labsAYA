#pragma once
class Pomesch
{
	string name;
	int id;
public:
	Pomesch *pnextPom;
	Pomesch();
	Pomesch(string);
	Pomesch(string, int);
	~Pomesch();
	Pomesch & operator = (Pomesch &t)
	{
		name = t.name;
		id = t.id;
		pnextPom = t.pnextPom;
		return (*this);
	}
	int getid()
	{
		return id;
	}
};