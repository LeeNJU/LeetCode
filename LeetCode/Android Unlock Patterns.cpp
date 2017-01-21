#include<vector>
//��Ŀ����:android����ģʽ������һ��3*3�����֣���1��9���ٸ���m��n����ʾ����ģʽ����С����󳤶ȣ������п��ܵ�
//        ����ģʽ�ĸ���������������־�����һ�����֣���ô�м�����ֱ�����֮ǰ�����ʹ�������1��9���м�ᾭ��5��
//        ��ô5��֮ǰ���뱻���ʹ���
//�ⷨ����:dfs,�ö�ά�����ʾÿ��������֮������֣��Լ���ǰ·�����Ѿ����ʹ������֣�����dfs������1,3,5,9�ǶԳƵ�
//        2,4,6,8Ҳ�ǶԳƵģ��Լ��м�һ��5������ֻ��Ҫ��1��ʼ�Ľ��������4,2��ʼ�Ľ������4������5��ʼ�Ľ��

int dfs(int m, int n, int len, int num, std::vector<bool>& visited, std::vector<std::vector<int>>& hash)
{
	int count = 0;
	if (len >= m) 
		count++;
	if (++len > n) 
		return count;
	
	visited[num] = true;
	for (int i = 1; i <= 9; ++i)
	{
		if (!visited[i] && visited[hash[num][i]])//��һ������û�б����ʹ��������м������Ѿ������ʹ�
			count += dfs(m, n, len, i, visited, hash);

	}
	visited[num] = false;
	
	return count;
}

int numberOfPatterns(int m, int n) 
{
	if (m < 1 || n < 1) 
		return 0;
	std::vector<bool> visited(10, false);
	visited[0] = true;
	std::vector<std::vector<int>> hash(10, std::vector<int>(10, 0));
	hash[1][3] = hash[3][1] = 2;//��¼���������м�����֣�����1��3֮����2,1��7֮����4
	hash[1][7] = hash[7][1] = 4;
	hash[3][9] = hash[9][3] = 6;
	hash[7][9] = hash[9][7] = 8;
	hash[2][8] = hash[8][2] = hash[4][6] = hash[6][4] = 5;
	hash[1][9] = hash[9][1] = hash[3][7] = hash[7][3] = 5;
	
	return dfs(m, n, 1, 1, visited, hash) * 4 + dfs(m, n, 1, 2, visited, hash) * 4 + dfs(m, n, 1, 5, visited, hash);
}