#include<vector>
#include<string>
#include<unordered_map>

//题目描述：给定一个DNA字符串，只包含C，G，A和T字符，找到其中出现次数大于1的长度为10的子串
//解法描述：用位操作，用2位就可以对CGAT进行编码，长度为10的子串只需要一个int的20位就可以了，用hashtable保存每个值
//         出现的次数，注意要去除重复元素

int getValue(char c)
{
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	else return 3;
}

std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
	std::vector<std::string> result;
	if (s.size() < 10)
		return result;

	std::unordered_map<int, int> m;
	int value = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		value = ((value << 2) | getValue(s[i])) & 0x000ffff; //注意这里，一个int的后20位是有效的，先左移动2位，
		                                                     //是为了把后一个字符的值加上去，然后与操作，把超过
		                                                     //出20位的位设为0
		if (i == 9)  //第一个元素
			++m[value];
		if (i > 9)
		{
			++m[value];
			if (m[value] > 1)
			{
				result.push_back(s.substr(i - 9, 10));
				m[value] = INT_MIN;  //这里注意，设为INT_MIN是为了防止出现重复元素，例如一个子串出现100次
			}
		}
	}
	return result;
}