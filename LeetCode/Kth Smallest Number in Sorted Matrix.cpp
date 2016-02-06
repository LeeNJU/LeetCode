#include<vector>
#include<algorithm>
//题目描述:给定一个矩阵，每一行每一列都已排好序，求第k小的元素
//解法描述:对每一列保存一个行index，每次找到最小的元素，然后行index向下移动，此题也可以用堆
int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
{
	if (matrix.empty())
		return 0;

	int col = matrix[0].size();
	std::vector<int> index(col, 0); //每一列保存一个行index

	int result = 0;
	for (int i = 0; i < k; ++i)
	{
		int min_index = 0;
		int min_val = INT_MAX;
		for (int j = 0; j < index.size(); ++j)
		{
			if (index[j] == -1) //这一列的元素已经被访问完
				continue;

			if (matrix[index[j]][j] < min_val) //找到最小元素在哪一列
			{
				min_val = matrix[index[j]][j];
				min_index = j;
			}
		}

		result = matrix[index[min_index]][min_index];
		++index[min_index];  //把最小元素的行index向下移动(加1)
		if (index[min_index] >= matrix.size()) //判断行index是否有效
			index[min_index] = -1;
	}
	return result;
}