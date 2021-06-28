#include "Header.h"
#include "PointEvent.h"

map<int, PointEvent> pointevents;

// �����ַ����Խ���. ����ʧ��return 1, ����return 0.
int analysis_pointevents(string str)
{
	// ֧��"//"��ͷ��ע��
	if (str[0] == '/' && str[1] == '/') return 0;

	string number_string = "", qqnumber_string = "", game_string = "", point_string = "";
	char team_char = ' ';
	int i = 0;

	for (; i != str.size() && !isdigit(str[i]); ++i); // ����ǰ��ķ������ַ�
	for (; i != str.size() && isdigit(str[i]); ++i) number_string += str[i];

	for (; i != str.size() && !isdigit(str[i]); ++i); // ����ǰ��ķ������ַ�
	for (; i != str.size() && isdigit(str[i]); ++i) qqnumber_string += str[i];

	for (; i != str.size() && str[i] != 't'; ++i); // ����th**_**ǰ����ַ�
	for (; i != str.size() && !isspace(str[i]); ++i) game_string += str[i];

	for (; i != str.size() && str[i] != 'A' && str[i] != 'B' && str[i] != 'C'; ++i); // ����A/B/Cǰ����ַ�
	if (i != str.size()) team_char = str[i];

	for (; i != str.size() && !isdigit(str[i]); ++i); // ����ǰ��ķ������ַ�
	for (; i != str.size() && isdigit(str[i]); ++i) point_string += str[i];

	if (number_string == "" || point_string == "") return 1; // ��ֹstoi����

	int number_int = stoi(number_string);
	PointEvent pointevent(qqnumber_string, game_string, team_char, stoi(point_string)); // �ر�ע�⣡����Ǽ�������
	pointevents.insert({ number_int, pointevent });
	return 0;
}

