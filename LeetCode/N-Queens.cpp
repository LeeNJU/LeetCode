#include<vector>
#include<string>

//��Ŀ������N�ʺ����⣬��n���ʺ�ŵ�n*n�������ϣ�ʹ���У��л�Խ����ϲ����໥����
//�ⷨ�������ݹ飬��row�����Ƶݹ���ȣ���һ��ݹ鵽��n�㣬ÿһ��ݹ��зֱ��ÿһ�е���������Ƿ���Է��ûʺ�

void dfs(int row, std::vector<int> &C, std::vector<std::vector<std::string> > &result, std::vector<int>& columns,
	std::vector<int>& principal_diagonals, std::vector<int>& counter_diagonals) 
{
	const int N = C.size();
	if (row == N) // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
	{ 
		std::vector<std::string> solution;
		for (int i = 0; i < N; ++i) 
		{
			std::string s(N, '.');
			for (int j = 0; j < N; ++j) 
			{
				if (j == C[i]) 
					s[j] = 'Q';
			}
			solution.push_back(s);
		}
		result.push_back(solution);
		return;
	}
	for (int j = 0; j < N; ++j) // ��չ״̬��һ��һ�е���
	{ 
		const bool ok = columns[j] == 0 && principal_diagonals[row + j] == 0 && counter_diagonals[row - j + N] == 0;
		if (ok) // ��֦������Ϸ��������ݹ�  ִ����չ����
		{ 
			C[row] = j;
			columns[j] = principal_diagonals[row + j] = counter_diagonals[row - j + N] = 1; //ͬһ�����Խ��ߵ��±�Ϊrow + j
			dfs(row + 1, C, result, columns, principal_diagonals, counter_diagonals); //ͬһ�����Խ����±�Ϊrow - j + N
			// ��������
			columns[j] = principal_diagonals[row + j] =
				counter_diagonals[row - j + N] = 0;
		}
	}
}

std::vector<std::vector<std::string> > solveNQueens(int n)
{
	std::vector<int> columns = std::vector<int>(n, 0);  //column���浱ǰ��Щ�б�ռ���ˣ������ٷŻʺ���
	std::vector<int> principal_diagonals = std::vector<int>(2 * n, 0); //principal_diagonals����ռ������Щ���Խ��ߣ����µ����ϵ�Ϊ���Խ���
	std::vector<int> counter_diagonals = std::vector<int>(2 * n, 0); //����ռ������Щ���Խ��ߣ����ϵ����µ�Ϊ���Խ���
	std::vector<std::vector<std::string> > result;
	std::vector<int> C(n, 0); // C[i] ��ʾ��i �лʺ����ڵ��б��
	dfs(0, C, result, columns, principal_diagonals, counter_diagonals); //rowΪ�������������Ƶݹ�����
	return result;
}
