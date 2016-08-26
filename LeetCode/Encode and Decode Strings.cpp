#include<string>
#include<vector>
//题目描述:字符串加密和解密，给定一个字符串数组，把字符串编码成一个字符串，然后对这个字符串解码得到原来的字符
//        串数组
//解法描述:编码规则，首先是字符串的长度，然后用一个特殊字符作为每个字符串的起始sentinel(如果不用sentinel,无
//        法得到字符串长度，因为字符串开头可能本身就包含数字)，然后是字符串
class Codec 
{
public:
	std::string encode(std::vector<std::string>& strs) 
	{
		std::string s;
		for (std::string str : strs)
			s += std::to_string(str.length()) + '#' + str;
		return s;
	}
	
	std::vector<std::string> decode(std::string s) 
	{
		std::vector<std::string> strs;
		size_t n = s.length(), p = 0;
		while (p < n) 
		{
			size_t pos = s.find('#', p);
			if (pos == std::string::npos) 
				break;

			size_t length = stoi(s.substr(p, pos - p));//得到字符串长度
			strs.push_back(s.substr(pos + 1, length));
			p = pos + length + 1;
		}
		return strs;
	}
};