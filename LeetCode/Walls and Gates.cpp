#include<vector>
#include<queue>
//题目描述:给定一个二维数组，0表示gate，-1表示obstacle，INF表示empty room,求每个empty room到最近的gate的距离
//解法描述:从gate出发，广搜，当前节点的位置是x和y，如果要周围的点的值比当前点的值大2，那么需要更新，如果周围点
//        的值比当前点的值小，就不需要更新

void wallsAndGates(std::vector<std::vector<int>>& rooms) 
{
    std::queue<int> gates;
	for (int i = 0; i < rooms.size(); ++i) 
	{
		for (int j = 0; j < rooms[i].size(); ++j) 
		{
			if (rooms[i][j] == 0)//找到所有的gate
			{
				gates.push(i);
				gates.push(j);
			}
		}
	}

	std::vector<int> dx = { 0, 0, 1, -1 };
	std::vector<int> dy = { -1, 1, 0, 0 };
	while (!gates.empty())
	{
		int x = gates.front();
		gates.pop();
		int y = gates.front();
		gates.pop();

		for (int i = 0; i < dx.size(); ++i)//上下左右4个点
		{
			if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= rooms.size() || 
				y + dy[i] >= rooms[0].size() || rooms[x + dx[i]][y + dy[i]] == -1 || 
				rooms[x][y] + 1 >= rooms[x + dx[i]][y + dy[i]])//下标越界或者为obstacle或者距离大于
				continue;

			rooms[x + dx[i]][y + dy[i]] = rooms[x][y] + 1;
			gates.push(x + dx[i]);
			gates.push(y + dx[i]);
		}
	}
}