#include<vector>
#include<queue>
//��Ŀ����:����һ����ά���飬0��ʾgate��-1��ʾobstacle��INF��ʾempty room,��ÿ��empty room�������gate�ľ���
//�ⷨ����:��gate���������ѣ���ǰ�ڵ��λ����x��y�����Ҫ��Χ�ĵ��ֵ�ȵ�ǰ���ֵ��2����ô��Ҫ���£������Χ��
//        ��ֵ�ȵ�ǰ���ֵС���Ͳ���Ҫ����

void wallsAndGates(std::vector<std::vector<int>>& rooms) 
{
    std::queue<int> gates;
	for (int i = 0; i < rooms.size(); ++i) 
	{
		for (int j = 0; j < rooms[i].size(); ++j) 
		{
			if (rooms[i][j] == 0)//�ҵ����е�gate
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

		for (int i = 0; i < dx.size(); ++i)//��������4����
		{
			if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= rooms.size() || 
				y + dy[i] >= rooms[0].size() || rooms[x + dx[i]][y + dy[i]] == -1 || 
				rooms[x][y] + 1 >= rooms[x + dx[i]][y + dy[i]])//�±�Խ�����Ϊobstacle���߾������
				continue;

			rooms[x + dx[i]][y + dy[i]] = rooms[x][y] + 1;
			gates.push(x + dx[i]);
			gates.push(y + dx[i]);
		}
	}
}