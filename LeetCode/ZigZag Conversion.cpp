#include<vector>
#include<string>
//题目描述：给定一个字符串s，把它转换成zigzag的格式，然后每一行从左往右读，形成一个新的字符串
//解法描述：找到数学规律，垂直元素的坐标(i; j) = (j + 1) * n + i，斜对角元素(i; j) = (j + 1) * n + i
std::string convert(std::string s, int numRows)
{
	if (numRows <= 1 || s.size() <= 1) 
		return s;
	
	std::string result;
	for (int i = 0; i < numRows; i++) //i和j为坐标，计算出要添加的元素在s中的下标index，把s[index]加入到result中 
	{
		for (int j = 0, index = i; index < s.size(); j++, index = (2 * numRows - 2) * j + i) 
		{
			result.append(1, s[index]); // 垂直元素
			if (i == 0 || i == numRows - 1) // 斜对角元素
				continue; 
			if (index + (numRows - i - 1) * 2 < s.size())
				result.append(1, s[index + (numRows - i - 1) * 2]);
		}
	}
	return result;
}