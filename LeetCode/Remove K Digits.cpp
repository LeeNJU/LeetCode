#include<string>
//题目描述:给定一个字符串表示一个数字，去掉其中的k个数字，使得剩下的数字是最小的，例如"1432219",k = 3,去掉
//        3个数字之后得到的最小数字是1219
//解法描述:遍历字符串，对于每个字符，如果比结果字符串的最后一个字符要小，说明能替换最后一个字符，组成更小的
//        数字，替换末尾比当前字符大的字符。这样进行替换之后，得到的字符串尽量会是递增的字符串

std::string removeKdigits(std::string num, int k) 
{
	std::string result = "";
	int n = num.size(), keep = n - k;
	for (char c : num) 
	{
		while (k && result.size() && result.back() > c) 
		{
			result.pop_back();
			--k;
		}
		result.push_back(c);
	}

	result.resize(keep);//注意这里要resize，因为可能删除的字符数不是k，这样得到的是递增序列
	while (!result.empty() && result[0] == '0')//去除前面的0 
		result.erase(result.begin());
	
	return result.empty() ? "0" : result;
}