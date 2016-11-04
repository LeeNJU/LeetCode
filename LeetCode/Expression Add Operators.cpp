#include<vector>
#include<string>

void dfs(std::vector<std::string> &result, std::string path, std::string num, int target, int index, 
			long cur, long prev)//cur表示到递归到当前，算出的值是多少，prev表示上一步的数字是多少
{
	if (index == num.size())
	{
		if (cur == target)   
			result.push_back(path);
		return;
	}

	for (int i = index; i < num.size(); ++i)
	{
		if (num[index] == '0' && i > index) //防止出现012这样的非法数字
			break;

		std::string str = num.substr(index, i - index + 1);
		long value = stol(str); //防止溢出
		if (index == 0)//注意这里
			dfs(result, path + str, num, target, i + 1, value, value);
		else
		{
			dfs(result, path + "+" + str, num, target, i + 1, cur + value, value);
			dfs(result, path + "-" + str, num, target, i + 1, cur - value, -value);//减号当成负数
			dfs(result, path + "*" + str, num, target, i + 1, cur - prev + prev * value, prev * value);
		}
	}
}

std::vector<std::string> addOperators(std::string num, int target) 
{
	std::vector<std::string> result;
	if (num.size() == 0)   
		return result;
	dfs(result, "", num, target, 0, 0, 0);
	return result;
}