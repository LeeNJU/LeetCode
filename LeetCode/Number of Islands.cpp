#include<vector>
//��Ŀ����������һ����ά����ֵΪ1����Ϊ0.�ҵ�����С���ĸ�����С���Ķ���Ϊ��0������1��С�����԰������1
//�ⷨ��������ÿһ��ֵΪ1�ĵ�������ѣ����ʹ��ĵ���б�ǣ�ÿ����һ��ֵΪ1����û�����ʹ��ĵ�ͱ�ʾ��һ��С�������Ѱ�
//         ��С���ϵĵ���б��
void dfs(std::vector<std::vector<char>>& grid, int i, int j, std::vector<std::vector<bool>>& visit)
{                             //���ѣ������ڵ�1���б��
	if (visit[i][j] || grid[i][j] == '0')
		return;

	visit[i][j] = true;
	if (i - 1 >= 0)
		dfs(grid, i - 1, j, visit);
	if (j - 1 >= 0)
		dfs(grid, i, j - 1, visit);
	if (j + 1 < grid[0].size())
		dfs(grid, i, j + 1, visit);
	if (i + 1 < grid.size())
		dfs(grid, i + 1, j, visit);

}
int numIslands(std::vector<std::vector<char>>& grid) 
{
	int count = 0;
	if (grid.empty())
		return count;

	std::vector<std::vector<bool>> visit(grid.size(), std::vector<bool>(grid[0].size(), false));
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '1' && !visit[i][j])//��ǰ�ĵ�Ϊ1������û�б����ʹ�
			{
				dfs(grid, i, j, visit);
				++count;
			}
		}
	}

	return count;
}