#pragma once

#include "Header.h"
#include "PointEvent.h"

// PersonLog�������ʽ����˱���
// key:
//     qqnumber: string
// private args:
//     point: int
//     pointevents: vector<PointEvent>
class PersonLog
{
public:
	// ���캯��
	PersonLog()
	{
		point = INITIAL_POINT;
		// pointevents������ʼΪ��
	}

	// ��������
	~PersonLog() {}

	// ��ȡpoint
	int read_point()
	{
		return point;
	}

	// д��pointevents�����������㵱ǰpoint���������ֵ
	// �ر�ע��˴�a_pointevent�������ţ�
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

