#include "Header.h"
#include "GameEvent.h"

map<int, string> gameevents_simple;
map<string, GameEvent> gameevents;

// �����ַ����Խ���. ����ʧ��return 1, ����return 0.
int analysis_gameevents(string str)
{
	string number_string = "", game_string = "";
	map<char, char> teamrank_map = { {'A', '-'}, {'B', '-'}, {'C', '-'} };
	int i = 0;
	int i_mark = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // ����ǰ��ķ������ַ�
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // ����th**_**ǰ����ַ�
	i_mark = i;
	for (; i != str.size() && i != i_mark + 7; ++i) game_string += str[i]; // ȡ��7���ַ�

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C'; ++i); // ����A/B/Cǰ����ַ�
	i_mark = i;
	// ѭ������
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
		return 1; // ��ֹstoi����
	}

	int number_int = stoi(number_string);
	gameevents_simple.insert({ number_int, game_string });
	GameEvent gameevent(number_int, teamrank_map);
	gameevents.insert({ game_string, gameevent });
	return 0;
}

