#pragma once
class Kategoriya
{
	string name;
	int num;
	Kategoriya *pnextKat;
public:
	Kategoriya();
	~Kategoriya();
	Kategoriya & operator = (Kategoriya &t)
	{
		name = t.name;
		num = t.num;
		pnextKat = t.pnextKat;
		return (*this);
	}
	int getNum();
};

