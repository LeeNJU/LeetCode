#include<string>
#include<vector>
#include<algorithm>
//题目描述:给定一个字符串和k，可以用任意字符替换字符串中的字符，最多替换k次，使得替换之后的字符串中存在子字符
//        串，子字符串的字符都相同，求这样的字符串的最大长度，例如"AABABBA", k = 1，把中间的A换成B，得到
//        "AABBBBA",最大的子字符串是"BBBB"，返回4
//解法描述:滑动窗口，记录滑动窗口中出现次数最多的字符，如果max_count加上k大于滑动窗口的大小，说明可以通过k次
//        操作把滑动窗口中的字符串变成相同的字符，如果max_count加上k小于滑动窗口的大小，如果向左移动滑动窗口

int characterReplacement(std::string s, int k) 
{
	std::vector<int> charCount(26, 0);
	int start = 0, max_count = 0;

	for (int end = 0; end < s.size(); ++end)
	{
		++charCount[s[end] - 'A'];
		max_count = std::max(max_count, charCount[s[end] - 'A']);
		if (max_count + k < end - start + 1)//不能通过k次操作把滑动窗口中的元素变成相同字符
		{
			--charCount[s[start] - 'A'];
			++start;
		}
	}
	return s.size() - start;
}