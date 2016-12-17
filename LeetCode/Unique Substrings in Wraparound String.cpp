#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
//题目描述:给定一个字符串p和s，s="...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...",s是
//        无限长的，要求p中有多少个唯一的子字符串也是s的子字符串，例如p="zab"，总共有6个子字符串，"z", 
//        "a", "b", "za", "ab", "zab",这6个子字符串都是s的子字符串
//解法描述:子字符串必须是连续的才是s的子字符串，所以只需要关注p中连续递增的子字符串，用一个数组分别记录以a，b
//        c,d,..,每个字符结束的连续递增的字符串的长度，例如"cdabcd"，以d为结束的连续递增的子字符串的长度是4，
//        然后对数组求和即可

int findSubstringInWraproundString(std::string p) 
{
	std::vector<int> count(26, 0);
	int maxLengthCur = 0;

	for (int i = 0; i < p.length(); ++i) 
	{
		if (i > 0 && (p[i] - p[i - 1] == 1 || (p[i - 1] - p[i] == 25))) 
			++maxLengthCur;
		else 
			maxLengthCur = 1;

		int index = p[i] - 'a';
		count[index] = std::max(count[index], maxLengthCur);
	}

	return std::accumulate(count.begin(), count.end(), 0);
}