#include "Header.h"
#include "PersonInfo.h"


int main()
{
	vector<PersonInfo> personlist;
	vector<string> giftlist;

	// ��ȷ��personlist.txt��giftlist.txt�ı��뷽ʽ�뱾����һ�£�ANSI/CRLF��
	ifstream file;
	string temp;
	string road = "personlist.txt"; file.open(road);
	cout << "personlist.txt open successfully!" << endl;
	while (getline(file, temp))
	{
		if (temp != "" && temp.size() > 2)
		{
			PersonInfo a_person(temp, (temp[0] - '0') + (temp[2] - '0') / 10.0);
			personlist.push_back(a_person);
		}
	}
	cout << "personlist.txt read successfully!" << endl;
	file.close();

	road = "giftlist.txt"; file.open(road);
	cout << "giftlist.txt open successfully!" << endl;
	while (getline(file, temp))
	{
		if (temp != "")
		{
			giftlist.push_back(temp);
		}
	}
	cout << "giftlist.txt read successfully!" << endl;
	file.close();

	// ������ܺ�
	double sum = 0.0;
	for (auto iter = personlist.begin(); iter != personlist.end(); ++iter)
	{
		sum += (*iter).printpoint();
	}

	default_random_engine e;
	e.seed((unsigned int)time(NULL));
	uniform_real_distribution<double> u(0.0, 1.0);

	// ��giftlist������������
	for (auto jter = giftlist.begin(); jter != giftlist.end(); ++jter)
	{
		getchar();
		double num = u(e);
		cout << "��Ʒ��" << *jter << endl << "�������" << num << endl;
		num *= sum;
		for (auto iter = personlist.begin(); iter != personlist.end(); ++iter)
		{
			double point = (*iter).ifgift(num, *jter);
			if (point < 0)
			{
				sum += point;
				break;
			}
			num -= point;
		}
		cout << "\n===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n" << endl;
	}

	for (auto iter = personlist.begin(); iter != personlist.end(); ++iter)
	{
		(*iter).printgift();
	}

	getchar();
	return 0;
}
