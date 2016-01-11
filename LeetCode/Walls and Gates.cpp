#include<vector>
#include<queue>
//题目描述:给定一个二维数组，0表示gate，-1表示obstacle，INF表示empty room,求每个empty room到最近的gate的距离
//解法描述:从gate出发，广搜
void wallsAndGates(std::vector<std::vector<int>>& rooms) 
{
    std::queue<int> gates;
	for (int i = 0; i<rooms.size(); i++) 
	{
		for (int j = 0; j<rooms[i].size(); j++) 
		{
			if (rooms[i][j] == 0)//找到所有的gate
			{
				gates.push(i);
				gates.push(j);
			}
		}
	}

	while (!gates.empty())
	{
		int x = gates.front();
		gates.pop();
		int y = gates.front();
		gates.pop();

		std::vector<int> dx = { 0, 0, 1, -1 };
		std::vector<int> dy = { -1, 1, 0, 0 };
		for (int i = 0; i < dx.size(); ++i)//上下左右4个点
		{
			if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= rooms.size() || 
				y + dy[i] >= rooms[0].size() || rooms[x + dx[i]][y + dy[i]] == 0 || 
				rooms[x + dx[i]][y + dy[i]] == -1)//下标越界或者为obstacle或者为gate
				continue;

			rooms[x + dx[i]][y + dy[i]] = std::min(rooms[x + dx[i]][y + dy[i]], rooms[x][y] + 1);
			gates.push(x + dx[i]);
			gates.push(y + dx[i]);
		}
	}
}