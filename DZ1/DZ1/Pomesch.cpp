#include "stdafx.h"
#include "Pomesch.h"


Pomesch::Pomesch()
{
	name = "NULL";
	id = 0;
	pnextPom = NULL;
}

Pomesch::Pomesch(string a)
{
	name = a;
	id = 0;
	pnextPom = NULL;
}

Pomesch::Pomesch(string a, int i)
{
	name = a;
	id = i;
	pnextPom = NULL;
}

Pomesch::~Pomesch()
{
}
