#include<string>
#include<vector>

//题目描述：给定一个值n，返回能够产生多少种的()序列，例如n=3，可以产生如下序列"((()))", "(()())", "(())()", 
//         "()(())", "()()()"
//解法描述：递归回溯法，每次先放(，再放)


void dfs(std::vector<std::string>& result, std::string intermediate, int left, int right, int n)//left和right
                                                                           //表示()剩下的个数
{
	if (intermediate.size() == n * 2)
	{
		result.push_back(intermediate);
		return;
	}

	if (left && left <= right) //left一定要小于right才能放
		dfs(result, intermediate + "(", left - 1, right, n);
	if (right && right > left)//right一定要大于left才能放
		dfs(result, intermediate + ")", left, right - 1, n);
}


std::vector<std::string> generateParenthesis(int n)
{
	std::vector<std::string> result;
	dfs(result, "", n, n, n);
	return result;
}