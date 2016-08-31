#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
//题目描述:给定一个字符串数组，返回所有的pair下标(i, j)，使得i字符串和j字符串连在一起是palindrome，例如
//        ["abcd", "dcba", "lls", "s", "sssll"],那么返回[[0, 1], [1, 0], [3, 2], [2, 4]]
//解法描述:用hash表存每个元素的下标，那么对于每个元素，考虑它所有的子字符串，例如"sssll", 其中的一个子串是
//        "ss",剩下的子串是"sll"，那么反转"sll"得到"lls",在hash表中查找该字符串，如果该字符串存在，那么把
//        该字符串放在左边，就可以组成palindrome。注意考虑空串的情况

bool isPalindrome(std::string& str)
{
	int left = 0, right = str.length() - 1;
	while (left < right)
	{
		if (str[left++] != str[right--])
			return false;
	}

	return true;
}

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words)
{
	std::vector<std::vector<int>> result;
	if (words.size() == 0 || words.size() < 2)
		return result;

	std::unordered_map<std::string, int> map;
	for (int i = 0; i < words.size(); ++i)//记录元素下标
		map[words[i]] = i;

	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words[i].length(); ++j)//考虑所有子字符串
		{
			std::string str1 = words[i].substr(0, j + 1);
			std::string str2 = words[i].substr(j + 1);

			if (isPalindrome(str1))
			{
				std::string rstr2(str2);
				std::reverse(rstr2.begin(), rstr2.end());//反转剩下的字符串
				if (map.find(rstr2) != map.end() && map[rstr2] != i)
					result.push_back({ map[rstr2], i });
			}
			if (isPalindrome(str2))
			{
				std::string rstr1(str1);
				std::reverse(rstr1.begin(), rstr1.end());

				if (map.find(rstr1) != map.end() && map[rstr1] != i)
					result.push_back({ map[rstr1], i });
			}
		}
	}

	return result;
}