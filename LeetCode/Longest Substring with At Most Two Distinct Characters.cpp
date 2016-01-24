#include<string>
#include<algorithm>
#include<unordered_map>
int lengthOfLongestSubstringTwoDistinct(std::string s)
{
	if (s.size() <= 2)
		return s.size();

	std::unordered_map<char, int> m;
	int count = 0;
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (m.find(s[j]) == m.end() && m.size() <= 2)
		{
			while (m.size() > 2)
			{
				--m[s[i]];
				if (m[s[i]] == 0)
					m.erase(s[i]);
			}
		}

		++m[s[j]];
		count = std::max(count, j - i + 1);
	}
	return count;
}