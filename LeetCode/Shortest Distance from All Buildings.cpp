#include<vector>
#include<queue>
#include<algorithm>
//��Ŀ����:����һ����ά����ֵΪ1����building��ֵΪ2����obstacle������ͨ����ֵΪ0����free land������Ҫѡ��һ��free
//        land,ʹ��free land�ĵ㵽����building�ĵ�ľ�����̣������������پ���|x1 - x2| + |y1 - y2|
//�ⷨ����:ɨ��ÿ��building���й��ѣ�distance[i][j]��ʾ����building���õ�ľ��룬reach[i][j]��ʾ���Ե���õ��building
int shortestDistance(std::vector<std::vector<int>>& grid)
{
	const int row = grid.size();
	if (row == 0)
		return -1;
	const int col = grid[0].size();

	std::vector<std::vector<int>> distance(row, std::vector<int>(col, 0));//building���ڵ�ľ���
	std::vector<std::vector<int>> reach(row, std::vector<int>(col, 0));//�ж��ٸ�building���Ե���ýڵ�
	int building = 0, res = INT_MAX;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
		// check from the building node, extend to all 0 node with distance
			if (grid[i][j] == 1)
			{
				++building;
				int dist = 0;
				std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
				std::queue<std::pair<int, int>> curLevel, nextLevel;
				curLevel.emplace(i, j);
				// bfs search for each current building
				while (!curLevel.empty())
				{
					++dist;
					while (!curLevel.empty())
					{
						std::pair<int, int> cur = curLevel.front();
						curLevel.pop();
						int x = cur.first, y = cur.second;
						++reach[x][y];
						std::vector<std::pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };//��������
						for (auto dir : dirs)
						{
							int i = x + dir.first, j = y + dir.second;
							if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() 
								&& grid[i][j] == 0 && !visited[i][j])
							{
								distance[i][j] += dist;
								nextLevel.emplace(i, j);
								visited[i][j] = true;
							}
						}
					}
					swap(curLevel, nextLevel);
				}
			}
		}
	}

	for (int i = 0; i < row; i++)//�ҵ��������Сֵ
	{
		for (int j = 0; j < col; j++)
		{
			if (0 == grid[i][j] && reach[i][j] == building)
				res = std::min(res, distance[i][j]);
		}
	}

	return res == INT_MAX ? -1 : res;
}