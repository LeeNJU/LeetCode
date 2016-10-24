#include<vector>
//题目描述:给定一个二位数组的board，'.'表示空，'X'表示一艘战舰，求出不同战舰的个数，一艘战舰只能是1 * N或者
//        N * 1的形式，N的大小不定，例如
//        X..X                       ...X
//        ...X                       XXXX
//        ...X    总共有两艘战舰      ...X 非法board，战舰之间至少有一个空格隔开
//解法描述:扫描数组，找到第一个战舰的第一个cell，如果一个cell的上一个位置或者左边一个位置也是战舰，那么这个
//        cell是战舰的一部分，其他为'X'的cell就是战舰的第一个cell

int countBattleships(std::vector<std::vector<char>>& board) 
{
	int m = board.size();
	if (m == 0) 
		return 0;
	int n = board[0].size();

	int count = 0;
	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j<n; ++j) 
		{
			if (board[i][j] == '.') 
				continue;
			if (i > 0 && board[i - 1][j] == 'X') 
				continue;
			if (j > 0 && board[i][j - 1] == 'X') 
				continue;
			count++;
		}
	}
	return count;
}