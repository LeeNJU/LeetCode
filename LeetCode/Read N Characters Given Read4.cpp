#include<algorithm>
//题目描述:给定read4函数，该函数每次读取4个字符，并返回读取的字符个数，如果只有3个字符，就只读3个字符，并返回
//        3，要求实现read函数读取n个字符
//解法描述:每次调用read4，n要减4
int read4(char* buf);
int read(char *buf, int n) 
{
	int res = 0;
	while (n > 0) 
	{
		int tmp = std::min(read4(buf), n);
		res += tmp;
		buf += tmp;
		if (tmp < 4)
			break;
		n -= 4;
	}
	return res;
}