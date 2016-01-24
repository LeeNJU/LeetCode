#include<vector>
//题目描述：给定一个整数n，产生对应的帕斯卡三角形
//解法描述：得到上一行的值，一次计算下一行的值

std::vector<std::vector<int> > generate(int numRows)
{
	std::vector<std::vector<int>> result;
	if (numRows == 0) 
		return result;
	result.push_back(std::vector<int>(1, 1)); //first row
	
	for (int i = 2; i <= numRows; ++i) 
	{
		std::vector<int> current(i, 1); // 本行
		const std::vector<int> &prev = result[i - 2]; // 上一行
		for (int j = 1; j < i - 1; ++j) 
			current[j] = prev[j - 1] + prev[j]; // 左上角和右上角之和
		result.push_back(current);
	}
	return result;
}

