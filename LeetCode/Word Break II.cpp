#include<vector>
#include<unordered_set>
#include<string>

void dfs(std::string& s, std::unordered_set<std::string>& wordDict, std::vector<bool> possible, std::vector<std::string>& result, std::string t, int start)
{
	if (start == s.length())
	{
		t.resize(t.size() - 1);
		result.push_back(t);
	}

	for (int i = start; i < s.length(); ++i)
	{
		std::string sub = s.substr(i, i - start + 1);
		if (wordDict.find(sub) != wordDict.end() && possible[start + 1])
		{
			possible[i] = true;
			t += sub;
			t += " ";
			dfs(s, wordDict, possible, result, t, i + 1);
		}
	}
}

std::vector<std::string> wordBreak(std::string s, std::unordered_set<std::string>& wordDict) 
{
	std::vector<std::string> result;
	std::vector<bool> possible(s.size() + 1, false);
	dfs(s, wordDict, possible, result, "", 0);
	return result;
}