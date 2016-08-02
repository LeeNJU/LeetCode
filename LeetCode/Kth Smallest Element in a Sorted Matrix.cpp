#include<vector>
//题目描述:给定一个二维数组，每行每列都已经排好序，要求第k个最小的元素
//解法描述:用一个数组保存当前每一列最小元素的下标，遍历这个一维数组，找到最小的元素，然后下标加1，可以用堆来
//        优化查找最小元素的时间。

int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
{
	std::vector<int> index(matrix.size(), 0);
	int result = INT_MAX;

	for (int i = 0; i < k; ++i)
	{
		int minimum = INT_MAX;
		int position = 0;
		for (int j = 0; j < index.size(); ++j)
		{
			if (index[j] < matrix.size() && matrix[index[j]][j] < minimum)//记录最小元素以及下标
			{
				minimum = matrix[index[j]][j];
				position = j;
			}
		}
		result = minimum;
		++index[position];
	}
	return result;
}