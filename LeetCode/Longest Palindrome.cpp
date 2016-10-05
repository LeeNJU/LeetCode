#include<string>
#include<unordered_map>
//题目描述:给定一个字符串，用其中的字符组成palindrome，找到能够组成的最长的palindrome的长度，例如"abccccdd"，
//        能够组成的最长的palindrome是"dccaccd"，长度是7
//解法描述:用hashtable存每个元素的次数，出现次数是偶数，就直接加到length中，如果是奇数，先减1，然后加到length
//        要注意奇数的个数，如果存在奇数次数，那么最后的结果要加1，也就是说把这个字符放到中间

int longestPalindrome(std::string s) 
{
	std::unordered_map<char, int> map;
	for (char c : s)
		++map[c];

	bool odd = false;//是否存在奇数次的字符
	auto iter = map.begin();
	int length = 0;
	while (iter != map.end())
	{
		if (iter->second % 2 == 0)
			length += iter->second;
		else
		{
			odd = true;
			length += (iter->second - 1);
		}
		++iter;
	}
	return odd ? length + 1 : length;
}