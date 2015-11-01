#include<string>

//题目描述：给定字符串PAYPALISHIRING，以如下方式解读：
//P   A   H   N
//A P L S I I G
//Y   I   R, 转换成PAHNAPLSIIGYIR，即一排排连起来
//解法描述：A到L的距离是固定的，先算A到P的距离2 * (n - 1 - i)，再算P到L的距离2 * i

std::string converts(std::string s, int numRows) {
	if (numRows <= 1)
		return s;

	std::string str = "";
	int index = 0;
	for (int i = 0; i < numRows && i < s.size(); ++i)
	{
		index = i;
		str += s[index];
		while (index < s.size())
		{
			index += (numRows - 1 - i) * 2;
			if ((numRows - 1 - i) * 2 != 0 && index < s.size())
				str += s[index];
			index += 2 * i;
			if (2 * i != 0 && index < s.size())
				str += s[index];
		}
	}
	return str;
}