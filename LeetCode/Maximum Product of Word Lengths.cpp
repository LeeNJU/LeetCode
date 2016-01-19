#include<string>
#include<vector>
//题目描述:给定一个字符串数组，找到两个字符串使得它们长度的乘积最大，并且这两个字符串之间没有公共字符
//解法描述:把每一个字符串转换成int数字，因为只有26个字母，可以用int值代替，然后进行与操作，如果没有公共字符，
//        与操作结果是0
int maxProduct(std::vector<std::string>& words)
{
	std::vector<int> vec(words.size(), 0);
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words[i].length(); ++j)
		{
			vec[i] |= (1 << (words[i][j] - 'a')); //转换成int值
		}
	}


	int result = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = i + 1; j < words.size(); ++j)
		{
			if (!(vec[i] & vec[j]) && words[i].length() * words[j].length() > result)
				result = words[i].length() * words[j].length();
		}
	}
	return result;
}