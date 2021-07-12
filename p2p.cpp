#include "Header.h"
#include "GameEvent.h"
#include "PointEvent.h"
#include "PersonLog.h"

extern vector<string> qqdata;

extern map<int, string> gameevents_simple;
extern map<string, GameEvent> gameevents;

extern map<int, PointEvent> pointevents;

map<string, PersonLog> personlogs;

int pointevents_to_personlogs()
{
	ofstream fout;
	fout.open("error.txt");

	// ������������pointevents����¼���󣬳������ൽgameevents��
	for (auto pointevents_iter = pointevents.begin(); pointevents_iter != pointevents.end(); ++pointevents_iter)
	{
		// ��ѹ
		int number = (*pointevents_iter).first;
		string qqnumber = (*pointevents_iter).second.read_qqnumber();
		string game = (*pointevents_iter).second.read_game();
		char team = (*pointevents_iter).second.read_team();
		int point = (*pointevents_iter).second.read_point();

		// QQ�Ų��߱��ʸ�
		if (find(qqdata.begin(), qqdata.end(), qqnumber) == qqdata.end())
		{
			cout << "Error Type 1: ���Ϊ" << number << "��QQ��" << qqnumber << "���߱��ʸ�" << endl;
			fout << "Error Type 1: ���Ϊ" << number << "��QQ��" << qqnumber << "���߱��ʸ�" << endl;
			continue;
		}
		auto gameevents_iter = gameevents.find(game);
		// ��Ŀ������
		if (gameevents_iter == gameevents.end())
		{
			cout << "Error Type 2: ���Ϊ" << number << "����Ŀ" << game << "������" << endl;
			fout << "Error Type 2: ���Ϊ" << number << "����Ŀ" << game << "������" << endl;
			continue;
		}
		// ��Ŀ��ʱ
		if (number > (*gameevents_iter).second.read_number())
		{
			cout << "Error Type 3: ���Ϊ" << number << "����Ŀ" << game << "֧����ʱ" << endl;
			fout << "Error Type 3: ���Ϊ" << number << "����Ŀ" << game << "֧����ʱ" << endl;
			continue;
		}

		auto personlogs_iter = personlogs.find(qqnumber);
		// ����û�������
		if (personlogs_iter == personlogs.end())
		{
			// �����û�
			personlogs.insert({ qqnumber, PersonLog() });
			// ���²�ѯ�û�
			personlogs_iter = personlogs.find(qqnumber);
		}
		// У�ԻƵ�
		int personlogs_point = (*personlogs_iter).second.read_point();
		if (personlogs_point <= 0)
			point = 0;
		else if (personlogs_point < 100)
			point = personlogs_point;
		else if (point < 100)
			point = 100;
		else if (point > personlogs_point)
			point = personlogs_point;

		// �Ǽǵ�personlogs
		// �Ǽǵ�ʱ���ø�����ʾ֧��
		(*personlogs_iter).second.write_pointevents(PointEvent(qqnumber, game, team, -point));
		// �ۼƻƵ㵽GameEvents
		(*gameevents_iter).second.add_teampoint(team, point);
		(*gameevents_iter).second.add_point_sum(point);
		if ((*gameevents_iter).second.read_teamrank(team) == '1')
		{
			(*gameevents_iter).second.add_point_winner(point);
			(*gameevents_iter).second.write_winner(PointEvent(qqnumber, game, team, point));
		}

		// ����Ƿ����GameEvents
		auto gameevents_simple_iter = gameevents_simple.find(number);
		if (gameevents_simple_iter != gameevents_simple.end())
		{
			string game_waiting_update = (*gameevents_simple_iter).second;
			gameevents[game_waiting_update].update_winner();
		}
	}

	fout.close();

	return 0;
}

