#pragma once

#include "Header.h"

// PointEvent���ʽ�����Ŀ��
// key:
//     number: int
// private args:
//     qqnumber: string
//     game: string
//     team: char
//     point: int
class PointEvent
{
public:
	// ���캯��
	PointEvent(string a_qqnumber, string a_game, char a_team, int a_point) :
		qqnumber(a_qqnumber), game(a_game), team(a_team), point(a_point) {}

	//PointEvent()
	//{
	//	qqnumber = "";
	//	game = "";
	//	team = 0;
	//	point = 0;
	//}

	// ��������
	~PointEvent() {}

	// ��ȡQQ��
	string read_qqnumber() { return qqnumber; }
	// ��ȡ��Ŀ
	string read_game() { return game; }
	// ��ȡ����
	char read_team() { return team; }
	// ��ȡpoint
	int read_point() { return point; }

	// ����point���õ���������
	void update_point(int point_sum, int point_winner)
	{
		point = (point * point_sum) / point_winner;
	}

	void def_print()
	{
		cout << qqnumber << " " << game << " " << team << " " << point << endl;
	}

private:
	string qqnumber;
	string game;
	char team;
	int point;
};

