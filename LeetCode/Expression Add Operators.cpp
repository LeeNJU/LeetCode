#include<vector>
#include<string>

void dfs(std::vector<std::string>& result, std::string t, const std::string& num, int index, int target)
{
	if (index == num.length())
	{
		if (target == 0)
			result.push_back(t);
		return;
	}

	if (stoi(num.substr(index)) == target)
	{
		result.push_back(t);
		return;
	}

	for (int i = index; i < num.size(); ++i)
	{
		std::string num1 = num.substr(index, i - index + 1);
		int val = stoi(num1);
		dfs(result, num1 + "+" + num.substr(i + 1), num, i + 1, target - val);
		dfs(result, num1 + "-" + num.substr(i + 1), num, i + 1, val - target);
		dfs(result, num1 + "*" + num.substr(i + 1), num, i + 1, target / val);
	}
}

std::vector<std::string> addOperators(std::string num, int target) 
{
	std::vector<std::string> result;
	dfs(result, "", num, 0, target);
	return result;
}