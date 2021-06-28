#include "Header.h"
#include "GameEvent.h"

map<int, string> gameevents_simple;
map<string, GameEvent> gameevents;

// 输入字符串以解析. 解析失败return 1, 否则return 0.
int analysis_gameevents(string str)
{
	string number_string = "", game_string = "";
	char team_char = 0;
	int i = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // 跳过前面的非数字字符
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // 跳过th**_**前面的字符
	for (; i != str.size() && !isspace(str[i]); ++i) game_string += str[i];

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C'; ++i); // 跳过A/B/C前面的字符
	if (i != str.size()) team_char = str[i];

	if (number_string == "") return 1; // 防止stoi报错

	int number_int = stoi(number_string);
	gameevents_simple.insert({ number_int, game_string });
	GameEvent gameevent(number_int, team_char);
	gameevents.insert({ game_string, gameevent });
	return 0;
}

