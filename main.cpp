#include "Header.h"
#include "GameEvent.h"
#include "PointEvent.h"
#include "PersonLog.h"

int read_file(string filename, int getlineAnalysis(string str));

extern vector<string> qqdata;
int analysis_qqdata(string str);

extern map<string, GameEvent> gameevents;
int analysis_gameevents(string str);

extern map<int, PointEvent> pointevents;
int analysis_pointevents(string str);

extern map<string, PersonLog> personlogs;
int pointevents_to_personlogs();

int main()
{
	// ��ȡQQ���б�qqdata.txt?��
	if (read_file("qqdata.txt", analysis_qqdata)) return 1;
	//for (vector<string>::iterator iter = qqdata.begin(); iter != qqdata.end(); ++iter)
	//	cout << *iter << endl;

	// ��ȡ���������¼��gameevents.txt?��
	if (read_file("gameevents.txt", analysis_gameevents)) return 1;
	//for (auto iter = gameevents.begin(); iter != gameevents.end(); ++iter)
	//{
	//	cout << (*iter).first << ": " << endl;
	//	(*iter).second.def_print();
	//}

	// ��ȡԭʼ��¼��pointevents.txt?��
	if (read_file("pointevents.txt", analysis_pointevents)) return 1;
	//for (auto iter = pointevents.begin(); iter != pointevents.end(); ++iter)
	//{
	//	cout << (*iter).first << ": " << endl;
	//	(*iter).second.def_print();
	//}

	if (pointevents_to_personlogs()) return 1;

	while (1)
	{
		cout << "\n��ѡ��\n1. ��ѯ�����ʽ���״��\n2. ��ѯ�����ʽ�����¼\n3. ��ѯ��Ŀ����\nq. �˳�" << endl;
		string choice; getline(cin, choice);
		if (choice[0] == '1')
		{
			for (auto iter = personlogs.begin(); iter != personlogs.end(); ++iter)
			{
				cout << (*iter).first << ": ";
				(*iter).second.def_print_point_only();
			}
		}
		else if (choice[0] == '2')
		{
			cout << "��������Ҫ��ѯ��QQ�ţ�" << endl;
			string qqnumber; getline(cin, qqnumber);
			auto iter = personlogs.find(qqnumber);
			if (iter == personlogs.end())
				cout << "�޷���ѯ��QQ��" << qqnumber << endl;
			else
				(*iter).second.def_print();
		}
		else if (choice[0] == '3')
		{
			cout << "��������Ҫ��ѯ����Ŀ��" << endl;
			string game; getline(cin, game);
			auto iter = gameevents.find(game);
			if (iter == gameevents.end())
				cout << "�޷���ѯ����Ŀ" << game << endl;
			else
				(*iter).second.def_abc();
		}
		else if (choice[0] == 'q')
		{
			break;
		}
		else
		{
			cout << "��Ч������" << endl;
		}
	}

	return 0;
}

