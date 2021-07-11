#pragma once

#include "Header.h"
#include "PointEvent.h"

// GameEvent：游戏项目类
// key:
//     game: string
// private args:
//     number: int
//     team: char
//     point_sum: int
//     point_winner: int
//     winner: vector<PointEvent>
class GameEvent
{
public:
	// 构造函数
	GameEvent(int a_number, char a_team) :
		number(a_number), team(a_team)
	{
		point_sum = 0;
		point_winner = 0;
		// winner为空容器
		point_a = 0, point_b = 0, point_c = 0;
	}

	GameEvent()
	{
		number = 0;
		team = 0;
		point_sum = 0;
		point_winner = 0;
		point_a = 0, point_b = 0, point_c = 0;
	}

	// 析构函数
	~GameEvent() {}

	// 读取序号
	int read_number() { return number; }
	// 读取队伍
	char read_team() { return team; }

	// 累加到point_sum
	void add_point_sum(int a_point) { point_sum += a_point; }
	// 累加到point_winner
	void add_point_winner(int a_point) { point_winner += a_point; }
	// 写入winner容器
	void write_winner(PointEvent a_pointevent) { winner.push_back(a_pointevent); }

	void add_point_abc(int a_point, char a_team)
	{
		if (a_team == 'A') point_a += a_point;
		else if (a_team == 'B') point_b += a_point;
		else if (a_team == 'C') point_c += a_point;
		else cout << "?" << endl;
	}

	// 统一更新winner容器
	void update_winner();

	void def_print()
	{
		cout << number << " " << team << endl;
		cout << point_sum << " " << point_winner << endl;
		for (vector<PointEvent>::iterator iter = winner.begin(); iter != winner.end(); ++iter)
		{
			(*iter).def_print();
		}
	}

	void def_abc()
	{
		cout << "Team A: " << point_a << " / " << point_sum << " ^-1 = " << 1.0 * point_sum / point_a << endl;
		cout << "Team B: " << point_b << " / " << point_sum << " ^-1 = " << 1.0 * point_sum / point_b << endl;
		cout << "Team C: " << point_c << " / " << point_sum << " ^-1 = " << 1.0 * point_sum / point_c << endl;
	}

private:
	int number;
	char team;
	int point_sum;
	int point_winner;
	int point_a;
	int point_b;
	int point_c;
	vector<PointEvent> winner;
};

