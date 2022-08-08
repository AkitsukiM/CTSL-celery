#pragma once

#include "Header.h"

class PersonInfo
{
public:
	// ���캯��
	PersonInfo(string a_name, double a_point) :
		name(a_name), point(a_point)
	{
		giftstat = 0;
		giftname = "";
	}

	// ��������
	~PersonInfo() {}

	// �ж��Ƿ��н����н����ظ�ֵ
	double ifgift(double num, string a_giftname)
	{
		// �����ѵý�
		if (giftstat == 1)
			return 0;
		// �ý�
		if (num < point)
		{
			giftstat = 1;
			giftname = a_giftname;
			cout << "���ߣ�" << name << endl;
			return -point;
		}
		// δ�ý�
		return point;
	}

	// ���������Ϣ
	double printpoint()
	{
		// cout << name << ": " << point << endl;
		return point;
	}

	// ����н���Ϣ
	void printgift()
	{
		if (giftstat == 1)
			cout << name << ": " << giftname << endl;
	}

private:
	string name;
	double point;
	int giftstat;
	string giftname;
};
