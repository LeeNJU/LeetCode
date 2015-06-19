#include<vector>
#include<string>

//题目描述：给定一个字符串数组和一个最大长度maxWidth，进行格式化，使得每一行字符串尽可能多的包含字符串数组中的字符串，并且长度不能超过最大长度
//解法描述：注意计算字符串的长度，如果长度超过最大长度，就添加空格形成一个合格的字符串，加入到result中

void addSpaces(std::string &s, int i, int n, int L, bool is_last) 
{
	if (n < 1 || i > n - 1) 
		return;
	int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
	s.append(spaces, ' ');
}

std::string connect(const std::vector<std::string> &words, int begin, int end, int len, int maxWidth, bool is_last) //根据begin和end的位置
{                                                                                                        //构造一行合格的字符串
	std::string s;
	int n = end - begin + 1;
	for (int i = 0; i < n; ++i) //单词逐个相连，并添加空格
	{
		s += words[begin + i];
		addSpaces(s, i, n - 1, maxWidth - len, is_last);
	}
	if (s.size() < maxWidth)  //补上末尾的空格
		s.append(maxWidth - s.size(), ' ');
	return s;
}

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
{
	std::vector<std::string> result;
	const int n = words.size();
	int begin = 0, len = 0; // 当前行的起点，当前长度
	for (int i = 0; i < n; ++i) 
	{
		if (len + words[i].size() + (i - begin) > maxWidth) //字符串长度加空格的数量如果超过最大长度 
		{
			result.push_back(connect(words, begin, i - 1, len, maxWidth, false));
			begin = i;
			len = 0;
		}
		len += words[i].size();  //各个字符串的长度累加
	}
	// 最后一行不足L
	result.push_back(connect(words, begin, n - 1, len, maxWidth, true));
	return result;
}