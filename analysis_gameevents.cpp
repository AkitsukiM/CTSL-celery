#include "Header.h"
#include "GameEvent.h"

map<int, string> gameevents_simple;
map<string, GameEvent> gameevents;

// 输入字符串以解析. 解析失败return 1, 否则return 0.
int analysis_gameevents(string str)
{
	string number_string = "", game_string = "";
	map<char, char> teamrank_map = { {'A', '-'}, {'B', '-'}, {'C', '-'} };
	int i = 0;
	int i_mark = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // 跳过前面的非数字字符
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // 跳过th**_**前面的字符
	i_mark = i;
	for (; i != str.size() && i != i_mark + 7; ++i) game_string += str[i]; // 取后7个字符

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C'; ++i); // 跳过A/B/C前面的字符
	i_mark = i;
	// 循环三次
	for (int t = 0; t != 3; ++t)
	{
		if ((str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
			&& (str[i + 1] == '-' || str[i + 1] == '1' || str[i + 1] == '2' || str[i + 1] == '3'))
		{
			teamrank_map[str[i]] = str[i + 1];
			i += 2;
		}
		else
		{
			cout << "teamrank_string: ";
			for (int j = i_mark; j != i_mark + 6; ++j) cout << str[j];
			cout << endl;
			return 1;
		}
	}

	if (number_string == "" || game_string == "")
	{
		cout << "number_string: " << number_string << "; game_string: " << game_string << endl;
		return 1; // 防止stoi报错
	}

	int number_int = stoi(number_string);
	gameevents_simple.insert({ number_int, game_string });
	GameEvent gameevent(number_int, teamrank_map);
	gameevents.insert({ game_string, gameevent });
	return 0;
}

