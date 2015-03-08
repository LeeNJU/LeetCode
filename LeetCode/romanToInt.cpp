#include<string>
#include<map>
//题目描述：把罗马数字转换成int，规则:I=1, V=5,X=10,L=50,C=100,D=500,M=1000,相同数字连写，表示数字相加，小数字在大数字右边，表示数字相加，小数字在大数字
//左边，表示大数字减去小数字
//解法描述：从左往右扫描,当遇到相同数字连写或者小数字在大数字右边是，都是表示直接把数字相加，而当小数字在大数字左边的时候，表示大数字减去小数字

int romanToInt(std::string s)
{
	std::map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	int result = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i > 0 && m[s[i]] > m[s[i - 1]])
			result += (m[s[i]] - 2 * m[s[i - 1]]);//注意要乘以2，例如XIX表示19，扫描到最后一个X时，其实I已经被加过一次了，所以要减去两倍
		else
			result += m[s[i]];
	}
	return result;
}