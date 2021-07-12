#pragma once

#include "Header.h"
#include "PointEvent.h"

// GameEvent����Ϸ��Ŀ��
// key:
//     game: string
// private args:
//     number: int
//     teamrank: map<char, char>
//     teampoint: map<char, int>
//     point_sum: int
//     point_winner: int
//     winner: vector<PointEvent>
class GameEvent
{
public:
	// ���캯��
	GameEvent(int a_number, map<char, char> a_teamrank) :
		number(a_number), teamrank(a_teamrank)
	{
		teampoint = { {'A', 0}, {'B', 0}, {'C', 0} };
		point_sum = 0;
		point_winner = 0;
		// winnerΪ������
	}

	GameEvent()
	{
		number = 0;
		teamrank = { {'A', '-'}, {'B', '-'}, {'C', '-'} };
		teampoint = { {'A', 0}, {'B', 0}, {'C', 0} };
		point_sum = 0;
		point_winner = 0;
		// winnerΪ������
	}

	// ��������
	~GameEvent() {}

	// ��ȡ���
	int read_number() { return number; }
	// ��ȡ��������
	char read_teamrank(char a_team) { return teamrank[a_team]; }

	// �ۼӵ�teampoint
	void add_teampoint(char a_team, int a_point)
	{
		teampoint[a_team] += a_point;
	}
	
	// �ۼӵ�point_sum
	void add_point_sum(int a_point) { point_sum += a_point; }
	// �ۼӵ�point_winner
	void add_point_winner(int a_point) { point_winner += a_point; }
	// д��winner����
	void write_winner(PointEvent a_pointevent) { winner.push_back(a_pointevent); }

	// ͳһ����winner����������ʵ��personlogs��
	void update_winner();

	void def_print()
	{
		cout << "number: " << number << endl;
		cout << "point_A: " << teampoint['A'] << endl;
		cout << "point_B: " << teampoint['B'] << endl;
		cout << "point_C: " << teampoint['C'] << endl;
		cout << "point_sum: " << point_sum << endl;
		cout << "point_winner: " << point_winner << endl;
		for (vector<PointEvent>::iterator iter = winner.begin(); iter != winner.end(); ++iter)
		{
			(*iter).def_print();
		}
	}

	void def_print_teampoint_odds()
	{
		int point_A = teampoint['A'], point_B = teampoint['B'], point_C = teampoint['C'];

		cout << "Team North: (" << point_A << " / " << point_sum << ") ^-1 = ";
		if (point_A != 0) cout << 1.0 * point_sum / point_A << endl;
		else cout << "inf" << endl;

		cout << "Team East : (" << point_B << " / " << point_sum << ") ^-1 = ";
		if (point_B != 0) cout << 1.0 * point_sum / point_B << endl;
		else cout << "inf" << endl;

		cout << "Team South: (" << point_C << " / " << point_sum << ") ^-1 = ";
		if (point_C != 0) cout << 1.0 * point_sum / point_C << endl;
		else cout << "inf" << endl;
	}

private:
	int number;
	map<char, char> teamrank;
	map<char, int> teampoint;
	int point_sum;
	int point_winner;
	vector<PointEvent> winner;
};

