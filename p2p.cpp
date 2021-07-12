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

	// 按序号升序遍历pointevents，记录错误，初步归类到gameevents中
	for (auto pointevents_iter = pointevents.begin(); pointevents_iter != pointevents.end(); ++pointevents_iter)
	{
		// 解压
		int number = (*pointevents_iter).first;
		string qqnumber = (*pointevents_iter).second.read_qqnumber();
		string game = (*pointevents_iter).second.read_game();
		char team = (*pointevents_iter).second.read_team();
		int point = (*pointevents_iter).second.read_point();

		// QQ号不具备资格
		if (find(qqdata.begin(), qqdata.end(), qqnumber) == qqdata.end())
		{
			cout << "Error Type 1: 序号为" << number << "的QQ号" << qqnumber << "不具备资格" << endl;
			fout << "Error Type 1: 序号为" << number << "的QQ号" << qqnumber << "不具备资格" << endl;
			continue;
		}
		auto gameevents_iter = gameevents.find(game);
		// 项目不存在
		if (gameevents_iter == gameevents.end())
		{
			cout << "Error Type 2: 序号为" << number << "的项目" << game << "不存在" << endl;
			fout << "Error Type 2: 序号为" << number << "的项目" << game << "不存在" << endl;
			continue;
		}
		// 项目超时
		if (number > (*gameevents_iter).second.read_number())
		{
			cout << "Error Type 3: 序号为" << number << "的项目" << game << "支付超时" << endl;
			fout << "Error Type 3: 序号为" << number << "的项目" << game << "支付超时" << endl;
			continue;
		}

		auto personlogs_iter = personlogs.find(qqnumber);
		// 如果用户不存在
		if (personlogs_iter == personlogs.end())
		{
			// 创建用户
			personlogs.insert({ qqnumber, PersonLog() });
			// 重新查询用户
			personlogs_iter = personlogs.find(qqnumber);
		}
		// 校对黄点
		int personlogs_point = (*personlogs_iter).second.read_point();
		if (personlogs_point <= 0)
			point = 0;
		else if (personlogs_point < 100)
			point = personlogs_point;
		else if (point < 100)
			point = 100;
		else if (point > personlogs_point)
			point = personlogs_point;

		// 登记到personlogs
		// 登记的时候用负数表示支付
		(*personlogs_iter).second.write_pointevents(PointEvent(qqnumber, game, team, -point));
		// 累计黄点到GameEvents
		(*gameevents_iter).second.add_teampoint(team, point);
		(*gameevents_iter).second.add_point_sum(point);
		if ((*gameevents_iter).second.read_teamrank(team) == '1')
		{
			(*gameevents_iter).second.add_point_winner(point);
			(*gameevents_iter).second.write_winner(PointEvent(qqnumber, game, team, point));
		}

		// 检测是否结算GameEvents
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

