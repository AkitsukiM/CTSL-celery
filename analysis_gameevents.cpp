#include "Header.h"
#include "GameEvent.h"

map<int, string> gameevents_simple;
map<string, GameEvent> gameevents;

// �����ַ����Խ���. ����ʧ��return 1, ����return 0.
int analysis_gameevents(string str)
{
	string number_string = "", game_string = "";
	char team_char = 0;
	int i = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // ����ǰ��ķ������ַ�
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // ����th**_**ǰ����ַ�
	int i7 = i + 7;
	for (; i != str.size() && i != i7; ++i) game_string += str[i];

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C' && str[i] != 'D'; ++i); // ����A/B/C/Dǰ����ַ�
	if (i != str.size()) team_char = str[i];

	if (number_string == "" || team_char == 0)
	{
		cout << "number_string: " << number_string
			<< "; team_char: 0" << endl;
		return 1; // ��ֹstoi����
	}

	int number_int = stoi(number_string);
	gameevents_simple.insert({ number_int, game_string });
	GameEvent gameevent(number_int, team_char);
	gameevents.insert({ game_string, gameevent });
	return 0;
}

