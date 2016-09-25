#include<string>
#include<unordered_map>
//题目描述:给定一个数字，求出16进制形式，例如给定26，返回"1a",给定-1，返回"ffffffff"
//解法描述:用哈希表保存每个数字对应的16进制形式，对于给定的数字，每次看最右边的4位，找到对应的16进制形式，
//        然后向右移动4位

std::string toHex(int num) 
{
	std::unordered_map<int, char> map;
	for (int i = 0; i < 10; ++i)
		map[i] = i + '0';

	map[10] = 'a';
	map[11] = 'b';
	map[12] = 'c';
	map[13] = 'd';
	map[14] = 'e';
	map[15] = 'f';

	int mask = 15;
	std::string s = "";
	for (int i = 0; i < 8; ++i)
	{
		int val = num & mask;
		s = map[val] + s;
		num = num >> 4;
	}

	int index = 0;
	while (index < s.size() - 1 && s[index] == '0')//去掉前面的0
		++index;

	return s.substr(index);
}