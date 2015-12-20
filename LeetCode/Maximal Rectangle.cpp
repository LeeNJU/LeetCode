#include<vector>
#include<algorithm>
//题目描述:给定一个矩阵，全是0和1，找到一个矩形，这个矩形全部是1，并且面积最大
//解法描述:求出每一行的高度，然后每一行按照Largest Reatangle 的解法求解
int largestRectangleArea(std::vector<int> height)
{
	std::vector<int> s;
	height.push_back(0);//插入高度为0的bar，是为了计算最后的递增序列的面积

	int sum = 0;
	int i = 0;
	while (i < height.size())
	{
		if (s.empty() || height[i] > height[s.back()]) //当前高度比栈顶元素小或者栈为空
		{
			s.push_back(i);
			i++;
		}
		else
		{
			int t = s.back();
			s.pop_back();
			//这里还需要考虑stack为空的情况
			sum = std::max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
		}
	}
	return sum;
}

int maximalRectangle(std::vector<std::vector<char>>& matrix) 
{
	if (matrix.empty())
		return 0;

	std::vector<std::vector<int>> height(matrix.size(), std::vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == '0')
				height[i][j] = 0;
			else
				height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
		}
	}

	int max_area = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		max_area = std::max(max_area, largestRectangleArea(height[i]));
	}
	return max_area;
}