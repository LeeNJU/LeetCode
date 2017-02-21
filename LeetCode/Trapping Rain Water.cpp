#include<vector>
#include<queue>
#include<algorithm>

//题目描述：给定一个高度数组，表明每个柱子的高度，求柱子之间能存多大的水量
//解法描述：记录第二高的柱子，从两边到中间，与第二高度的差就是水量
//          http://fisherlei.blogspot.com/2013/01/leetcode-trapping-rain-water.html
int trap(std::vector<int>& height)
{
	int secHight = 0;
	int left = 0;
	int right = height.size() - 1;
	int area = 0;
	while (left < right)
	{
		if (height[left] < height[right])
		{
			secHight = std::max(height[left], secHight);
			area += secHight - height[left];//计算当前格的能装雨水的容量
			left++;
		}
		else 
		{
			secHight = std::max(height[right], secHight);
			area += secHight - height[right];
			right--;
		}
	}
	return area;
}

//题目描述:给定一个二维矩阵，每个元素表示高度，求在这个二维数组里能装多少水
//解法描述:从外到内扫描，先把边界上的点加入到最小堆里，依次取出堆里的元素，查看周围没有被访问过的元素，如果高度
//        比当前高度小，记录水量，标记为visited

struct Cell
{
	int row;
	int col;
	int height;
	Cell(int r = 0, int c = 0, int h = 0) : row(r), col(c), height(h){};
	bool operator() (const Cell& cell1, const Cell& cell2)
	{
		return cell1.height < cell2.height;
	}
};

int trapRainWater(std::vector<std::vector<int>>& heightMap) 
{
	if (heightMap.empty())
		return 0;

	std::priority_queue<Cell, std::vector<Cell>, Cell> queue;
	int n = heightMap.size();
	int m = heightMap[0].size();
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
	{
		visited[i][0] = true;
		visited[i][m - 1] = true;
		queue.push(Cell(i, 0, heightMap[i][0]));
		queue.push(Cell(i, m - 1, heightMap[i][m - 1]));
	}

	for (int i = 0; i < m; ++i)
	{
		visited[0][i] = true;
		visited[n - 1][i] = true;
		queue.push(Cell(0, i, heightMap[0][i]));
		queue.push(Cell(n - 1, i, heightMap[n - 1][i]));
	}

	int result = 0;
	std::vector<int> dx = { 1, -1, 0, 0 };
	std::vector<int> dy = { 0, 0, 1, -1 };

	while (!queue.empty())
	{
		Cell cell = queue.top();
		queue.pop();

		for (int i = 0; i < dx.size(); ++i)
		{
			int x = cell.row + dx[i];
			int y = cell.col + dy[i];

			if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y])
			{
				visited[x][y] = true;
				result += std::max(0, cell.height - heightMap[x][y]);
				queue.push(Cell(x, y, std::max(heightMap[x][y], cell.height)));//注意这里，要去二者的最大值
			}
		}
	}

	return result;
}