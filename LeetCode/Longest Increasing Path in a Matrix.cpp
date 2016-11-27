#include<vector>
#include<algorithm>
//题目描述:给定一个二维数组，找到其中最长的递增序列，返回其长度
//解法描述:深搜，注意剪枝，用一个length数组保存当前位置的递增序列的长度，用来剪枝

void dfs(const std::vector<std::vector<int>>& matrix, int i, int j,
	std::vector<std::vector<int>>& length, int& max_length, int cur_length)
{
	if (cur_length <= length[i][j])
		return;

	length[i][j] = cur_length;
	max_length = std::max(max_length, length[i][j]);
	if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
		dfs(matrix, i - 1, j, length, max_length, cur_length + 1);
	if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
		dfs(matrix, i, j - 1, length, max_length, cur_length + 1);
	if (i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
		dfs(matrix, i + 1, j, length, max_length, cur_length + 1);
	if (j + 1 < matrix[0].size() && matrix[i][j + 1] > matrix[i][j])
		dfs(matrix, i, j + 1, length, max_length, cur_length + 1);

}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
{
	if (matrix.empty())
		return 0;

	std::vector<std::vector<int>> length(matrix.size(), std::vector<int>(matrix[0].size(), 0));
	int max_length = 1;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			dfs(matrix, i, j, length, max_length, 1);
		}
	}
	return max_length;
}