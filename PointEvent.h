#pragma once

#include "Header.h"

// PointEvent：资金力账目类
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
	// 构造函数
	PointEvent(string a_qqnumber, string a_game, char a_team, int a_point) :
		qqnumber(a_qqnumber), game(a_game), team(a_team), point(a_point) {}

	//PointEvent()
	//{
	//	qqnumber = "";
	//	game = "";
	//	team = 0;
	//	point = 0;
	//}

	// 析构函数
	~PointEvent() {}

	// 读取QQ号
	string read_qqnumber() { return qqnumber; }
	// 读取项目
	string read_game() { return game; }
	// 读取队伍
	char read_team() { return team; }
	// 读取point
	int read_point() { return point; }

	// 覆盖point，用的是整数除
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

