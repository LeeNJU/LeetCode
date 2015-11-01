#include<vector>
#include<string>
//题目描述:给定一个字符串，例如2-1-1，添加括号，使得算出的值不同，问有多少种不同的结果
//解法描述:递归，以运算符号为中心进行划分，运算符两边分别求出不同的左值和右值，然后根据左值和右值的集合，进行计算
//        应该要考虑计算结果的唯一行
std::vector<int> diffWaysToCompute(std::string input) 
{
	std::vector<int> result;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*')
		{
			std::vector<int> left_value = diffWaysToCompute(input.substr(0, i));//遇到运算符号，对两边进行划分
			std::vector<int> right_value = diffWaysToCompute(input.substr(i + 1));
			for (int m = 0; m < left_value.size(); ++m)//对左值和右值进行计算
			{
				for (int n = 0; n < right_value.size(); ++n)
				{
					if (input[i] == '+')
						result.push_back(left_value[m] + right_value[n]);
					else if (input[i] == '-')
						result.push_back(left_value[m] - right_value[n]);
					else if (input[i] == '*')
						result.push_back(left_value[m] * right_value[n]);
				}
			}
		}
	}

	if (result.empty())//result为空，说明没有运算符，input就是一个单独的数字
		result.push_back(stoi(input));
	return result;
}
