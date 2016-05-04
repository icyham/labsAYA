#include "stdafx.h"
#include "Kategoriya.h"


Kategoriya::Kategoriya()
{
	name = "NULL";
	num = 0;
	pnextKat = NULL;
}

Kategoriya::Kategoriya(string a)
{
	name = a;
	num = 0;
	pnextKat = NULL;
}

Kategoriya::Kategoriya(string a, int n)
{
	name = a;
	num = n;
	pnextKat = NULL;
}

Kategoriya::~Kategoriya()
{
}
