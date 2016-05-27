#pragma once
class Kategoriya
{
	string name;
	int num;
public:
	Kategoriya *pnextKat;
	Kategoriya();
	Kategoriya(string);
	Kategoriya(string, int);
	~Kategoriya();
	Kategoriya & operator = (Kategoriya &t)
	{
		name = t.name;
		num = t.num;
		pnextKat = t.pnextKat;
		return (*this);
	}
	int getnum()
	{
		return this->num;
	}
};

