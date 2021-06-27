#include "Header.h"

vector<string> qqdata;

// 输入字符串以解析. 解析失败return 1, 否则return 0.
int analysis_qqdata(string str)
{
	string qqnumber_string = "";
	int i = 0;

	// 从第一个数字字符开始到第一个非数字字符结束
	for (; i != str.size() && !isdigit(str[i]); ++i);
	for (; i != str.size() && isdigit(str[i]); ++i) qqnumber_string += str[i];
	qqdata.push_back(qqnumber_string);
	return 0;
}

