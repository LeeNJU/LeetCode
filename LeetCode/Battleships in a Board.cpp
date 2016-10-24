#include<vector>
//��Ŀ����:����һ����λ�����board��'.'��ʾ�գ�'X'��ʾһ��ս���������ͬս���ĸ�����һ��ս��ֻ����1 * N����
//        N * 1����ʽ��N�Ĵ�С����������
//        X..X                       ...X
//        ...X                       XXXX
//        ...X    �ܹ�������ս��      ...X �Ƿ�board��ս��֮��������һ���ո����
//�ⷨ����:ɨ�����飬�ҵ���һ��ս���ĵ�һ��cell�����һ��cell����һ��λ�û������һ��λ��Ҳ��ս������ô���
//        cell��ս����һ���֣�����Ϊ'X'��cell����ս���ĵ�һ��cell

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