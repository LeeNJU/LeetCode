#include<vector>
#include<algorithm>

int longestIncreasingPath(std::vector<std::vector<int>>& matrix) 
{
	if (matrix.empty())
		return 0;

	int result = 0;
	std::vector<std::vector<int>> length(matrix.size(), std::vector<int>(matrix[0].size(), 1));
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.size(); ++j)
		{
			if (i + 1 < matrix.size() && matrix[i + 1][j] < matrix[i][j])
				length[i][j] = std::max(length[i][j], length[i + 1][j] + 1);
			if (j + 1 < matrix[0].size() && matrix[i][j + 1] < matrix[i][j])
				length[i][j] = std::max(length[i][j], length[i][j + 1] + 1);
			if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j])
				length[i][j] = std::max(length[i][j], length[i - 1][j] + 1);
			if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j])
				length[i][j] = std::max(length[i][j], length[i][j - 1] + 1);

			result = std::max(result, length[i][j]);
		}
	}
	return result;
}