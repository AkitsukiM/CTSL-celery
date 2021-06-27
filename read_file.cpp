#include "Header.h"

int read_file(string filename, int getlineAnalysis(string str))
{
	// 寻找相对路径下的filename
	ifstream file;
	string road = filename; file.open(road);
	// 找不到filename
	if (!file.is_open())
	{
		file.close();
		cout << "Cannot find " << filename << ". Enter the path of a specific file." << endl;
		getline(cin, road); file.open(road);
	}
	// 如果依然找不到
	if (!file.is_open())
	{
		file.close();
		cout << "Error: Cannot find \"" << road << "\"." << endl;
		return 1; // 返回1表示失败
	}

	cout << filename << " open successfully!" << endl;
	string temp;
	while (getline(file, temp))
	{
		if (temp != "" && getlineAnalysis(temp)) // 非空字符串解析失败
		{
			cout << "Error: illegal information in line \"" << temp << "\"" << endl;
			return 1; // 返回1表示失败
		}
	}

	cout << filename << " read successfully!" << endl;
	file.close();
	return 0;
}

