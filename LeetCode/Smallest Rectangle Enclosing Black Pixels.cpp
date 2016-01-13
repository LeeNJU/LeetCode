#include<vector>
#include<queue>
#include<algorithm>
//题目描述:给定一个二维字符数组，值为0和1，所有的1都是相连的，现在给定一个1的坐标x和y，求出最小的并且包含所有1
//        的长方形的面积
//解法描述:bfs，搜索所有节点，并保存1的最大行，最小行，最大列和最小列的下标
int minArea(std::vector<std::vector<char>>& image, int x, int y)
{
	if (image.empty())
		return 0;

	int min_row = 0, min_col = 0, max_row = image.size() - 1, max_col = image[0].size() - 1;
	std::queue<int> q;
	q.push(x);
	q.push(y);

	while (!q.empty())
	{
		int row = q.front();
		q.pop();
		int col = q.front();
		q.pop();
		if (image[row][col] == '0')//利用image数组来进行标记，已访问过
			continue;
		image[row][col] = '0';

		min_row = std::max(min_row, x);
		min_col = std::max(min_col, y);
		max_row = std::min(max_row, x);
		max_col = std::min(max_col, y);

		if (row + 1 < image.size() && image[row + 1][col] == '1')
		{
			q.push(row + 1);
			q.push(col);
		}

		if (row - 1 >= 0 && image[row - 1][col] == '1')
		{
			q.push(row - 1);
			q.push(col);
		}

		if (col + 1 && image[row][col + 1] == '1')
		{
			q.push(row);
			q.push(col + 1);
		}

		if (col - 1 >= 0 && image[row][col - 1])
		{
			q.push(row);
			q.push(col - 1);
		}
	}

	return (max_row - min_row + 1) * (max_col - min_col + 1);
}