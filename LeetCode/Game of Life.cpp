#include<vector>
//��Ŀ����:����һ����άboard��ֵΪ1����live��ֵΪ0����die��ÿһ��ֵ��8��neighbor(�������ҶԽ���)�����ֵΪ1����neighbor
//        ֵΪ1�ĸ���С��2����һ��ֵ����0�����ֵΪ1����neighbor��ֵΪ1�ĸ���Ϊ2����3��ֵ��Ϊ1�����ֵΪ1����neighbor
//        ��ֵΪ1�ĸ�������3����һ��ֵ���0�����ֵΪ0������3��ֵΪ1 ��neighbor����һ������1,Ҫ�������һ��֮�����е�ֵ
//�ⷨ����:��0��1��2��3����ʾ״̬��0��ʾdie->die, 1��ʾlive->live, 2��ʾlive->die,3��ʾdie->live��Ȼ��ͳ��ÿ��cell��
//        neighbor�趨״̬�����״̬Ϊ0����2�ı��die��1����3���live
void gameOfLife(std::vector<std::vector<int>>& board) 
{
	int m = board.size();
	int n = m ? board[0].size() : 0;
	std::vector<int> dx = { -1, -1, -1, 0, 1, 1, 1, 0 };
	std::vector<int> dy = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			int count = 0;
			for (int k = 0; k < 8; ++k) //ͳ����ΧneighborΪlive�ĸ���
			{
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) 
					++count;
			}
			if (board[i][j] && (count < 2 || count > 3)) //����neighbor�����趨״̬
				board[i][j] = 2;
			else if (!board[i][j] && count == 3) 
				board[i][j] = 3;
		}
	}
	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j < n; ++j) 
			board[i][j] %= 2;
	}
}