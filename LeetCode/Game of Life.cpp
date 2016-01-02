#include<vector>
//题目描述:给定一个二维board，值为1代表live，值为0代表die。每一个值的8个neighbor(上下左右对角线)，如果值为1并且neighbor
//        值为1的个数小于2，下一步值会变成0，如果值为1并且neighbor中值为1的个数为2或者3，值仍为1，如果值为1并且neighbor
//        中值为1的个数大于3，下一步值变成0，如果值为0并且有3个值为1 的neighbor，下一步会变成1,要求计算下一步之后所有的值
//解法描述:用0，1，2，3来表示状态，0表示die->die, 1表示live->live, 2表示live->die,3表示die->live，然后统计每个cell的
//        neighbor设定状态，最后状态为0或者2的变成die，1或者3变成live
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
			for (int k = 0; k < 8; ++k) //统计周围neighbor为live的个数
			{
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) 
					++count;
			}
			if (board[i][j] && (count < 2 || count > 3)) //根据neighbor数量设定状态
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