#pragma once

#include "Header.h"
#include "PointEvent.h"

// PersonLog：个人资金力账本类
// key:
//     qqnumber: string
// private args:
//     point: int
//     pointevents: vector<PointEvent>
class PersonLog
{
public:
	// 构造函数
	PersonLog()
	{
		point = INITIAL_POINT;
		// pointevents容器初始为空
	}

	// 析构函数
	~PersonLog() {}

	// 读取point
	int read_point()
	{
		return point;
	}

	// 写入pointevents容器，并计算当前point，返回这个值
	// 特别注意此处a_pointevent的正负号！
	int write_pointevents(PointEvent a_pointevent)
	{
		pointevents.push_back(a_pointevent);
		point += a_pointevent.read_point();
		return point;
	}

	void def_print_point_only()
	{
		cout << point << endl;
	}

	void def_print()
	{
		cout << point << endl;
		for (vector<PointEvent>::iterator iter = pointevents.begin(); iter != pointevents.end(); ++iter)
			(*iter).def_print();
	}

private:
	int point;
	vector<PointEvent> pointevents;
};

