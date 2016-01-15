#include<string>
#include<algorithm>

int lengthOfLongestSubstringTwoDistinct(std::string s)
{
	int i = 0, j = -1;
	int maxLen = 0;
	for (int k = 1; k < s.size(); k++)
	{
		if (s[k] == s[k - 1])
			continue;
		if (j > -1 && s[k] != s[j])
		{
			maxLen = max(maxLen, k - i);
			i = j + 1;
		}
		j = k - 1;
	}
	return maxLen > (s.size() - i) ? maxLen : s.size() - i;
}