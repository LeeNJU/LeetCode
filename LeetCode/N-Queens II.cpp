#include<vector>

//��Ŀ������N�ʺ����⣬�����ĸ���
//�ⷨ����������һ������
void dfs(int row, std::vector<int>& columns, std::vector<int>& principal_diagonals, std::vector<int>& counter_diagonals, int& count)
{
	const int N = columns.size();
	if (row == N) // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
	{
		++count;
		return;
	}
	for (int j = 0; j < N; ++j) // ��չ״̬��һ��һ�е���
	{
		const bool ok = columns[j] == 0 && principal_diagonals[row + j] == 0 && counter_diagonals[row - j + N] == 0;
		if (ok) // ��֦������Ϸ��������ݹ� ִ����չ����
		{
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1;
			dfs(row + 1, columns, principal_diagonals, counter_diagonals, count);
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 0;
		}
	}
}

int totalNQueens(int n)
{
	int count = 0;
	std::vector<int> columns = std::vector<int>(n, 0);
	std::vector<int> principal_diagonals = std::vector<int>(2 * n, 0);
	std::vector<int> counter_diagonals = std::vector<int>(2 * n, 0);
	dfs(0, columns, principal_diagonals, counter_diagonals, count);
	return count;
}