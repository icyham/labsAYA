#pragma once
//�������: ���������, ��������, ����������������, ��������� �� �������
class Matrixx
{
	int row, col; //������� �������
public:
	double* data;
	Matrixx(void);
	Matrixx(int row);
	Matrixx(int row, int col);
	~Matrixx(void);

	int getrow(Matrixx);
	int getcol(Matrixx);
	static int printmat(Matrixx);
	Matrixx & operator = (Matrixx &c);
	Matrixx operator + (Matrixx &c);
	Matrixx operator * (Matrixx &c);
	double Matrindex (Matrixx t, int i, int j);
	friend Matrixx & operator ~(Matrixx &t);
};

