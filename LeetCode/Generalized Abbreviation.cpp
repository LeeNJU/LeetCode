#include<string>
#include<vector>
//题目描述:给定字符串，求出所有可能的缩写，例如给定"word",那么可能的缩写结果是["word", "1ord", "w1rd", "wo1d", "wor1",
//        "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//解法描述:递归穷举，每一个字符有两种可能，进行缩写和不进行缩写，如果进行缩写，就要避免连续的数字
void dfs(std::string& word, std::string t, int i, std::vector<std::string>& result, bool prevNum)
{                         //prevNum表示上一步是否添加数字
	if (i == word.length())
	{
		result.push_back(t);
		return;
	}

	dfs(word, t + word[i], i + 1, result, false);//不进行缩写
	if (!prevNum)//上一步没有添加数字
	{
		for (int len = 1; i + len <= word.length(); ++len) 
			dfs(word, t + std::to_string(len), i + len, result, true);
	}
}

std::vector<std::string> generateAbbreviations(std::string word) 
{
	std::vector<std::string> result;
	dfs(word, "", 0, result, false);
	return result;
}