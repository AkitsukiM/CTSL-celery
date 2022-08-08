#pragma once

#include "Header.h"

class PersonInfo
{
public:
	// 构造函数
	PersonInfo(string a_name, double a_point) :
		name(a_name), point(a_point)
	{
		giftstat = 0;
		giftname = "";
	}

	// 析构函数
	~PersonInfo() {}

	// 判断是否中奖，中奖返回负值
	double ifgift(double num, string a_giftname)
	{
		// 跳过已得奖
		if (giftstat == 1)
			return 0;
		// 得奖
		if (num < point)
		{
			giftstat = 1;
			giftname = a_giftname;
			cout << "获奖者：" << name << endl;
			return -point;
		}
		// 未得奖
		return point;
	}

	// 输出点数信息
	double printpoint()
	{
		// cout << name << ": " << point << endl;
		return point;
	}

	// 输出中奖信息
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
