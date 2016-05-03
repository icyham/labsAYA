#pragma once
class Pomesch
{
	string name;
	int id;
	Pomesch *pnextPom;
public:
	Pomesch();
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
	//friend void newPom(Pomesch* plast , Pomesch* pnew);
	//friend void obedin(Pomesch* pfirst, Pomesch* psecond);
};