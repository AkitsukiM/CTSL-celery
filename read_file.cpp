#include "Header.h"

int read_file(string filename, int getlineAnalysis(string str))
{
	// Ѱ�����·���µ�filename
	ifstream file;
	string road = filename; file.open(road);
	// �Ҳ���filename
	if (!file.is_open())
	{
		file.close();
		cout << "Cannot find " << filename << ". Enter the path of a specific file." << endl;
		getline(cin, road); file.open(road);
	}
	// �����Ȼ�Ҳ���
	if (!file.is_open())
	{
		file.close();
		cout << "Error: Cannot find \"" << road << "\"." << endl;
		return 1; // ����1��ʾʧ��
	}

	cout << filename << " open successfully!" << endl;
	string temp;
	while (getline(file, temp))
	{
		if (temp != "" && getlineAnalysis(temp)) // �ǿ��ַ�������ʧ��
		{
			cout << "Error: illegal information in line \"" << temp << "\"" << endl;
			return 1; // ����1��ʾʧ��
		}
	}

	cout << filename << " read successfully!" << endl;
	file.close();
	return 0;
}

