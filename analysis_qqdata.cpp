#include "Header.h"

vector<string> qqdata;

// �����ַ����Խ���. ����ʧ��return 1, ����return 0.
int analysis_qqdata(string str)
{
	string qqnumber_string = "";
	int i = 0;

	// �ӵ�һ�������ַ���ʼ����һ���������ַ�����
	for (; i != str.size() && !isdigit(str[i]); ++i);
	for (; i != str.size() && isdigit(str[i]); ++i) qqnumber_string += str[i];
	qqdata.push_back(qqnumber_string);
	return 0;
}

