#include "Header.h"
#include "PointEvent.h"

map<int, PointEvent> pointevents;

// 输入字符串以解析. 解析失败return 1, 否则return 0.
int analysis_pointevents(string str)
{
	// 支持"//"开头的注释
	if (str[0] == '/' && str[1] == '/') return 0;

	string number_string = "", qqnumber_string = "", game_string = "", point_string = "";
	char team_char = ' ';
	int i = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // 跳过前面的非数字字符
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && !isdigit(str[i]); ++i); // 跳过前面的非数字字符
	for (; i != str.size() && isdigit(str[i]); ++i) qqnumber_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // 跳过th**_**前面的字符
	for (; i != str.size() && !isspace(str[i]); ++i) game_string += str[i];

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C'; ++i); // 跳过A/B/C前面的字符
	if (i != str.size()) team_char = str[i];

	for (; i != str.size() && !isdigit(str[i]); ++i); // 跳过前面的非数字字符
	for (; i != str.size() && isdigit(str[i]); ++i) point_string += str[i];

	if (number_string == "" || point_string == "") return 1; // 防止stoi报错

	int number_int = stoi(number_string);
	PointEvent pointevent(qqnumber_string, game_string, team_char, stoi(point_string)); // 特别注意！这里登记是正数
	pointevents.insert({ number_int, pointevent });
	return 0;
}

