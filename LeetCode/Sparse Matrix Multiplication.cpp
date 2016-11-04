#include<vector>
//��Ŀ����:��������ϡ����������ǵĳ˻�
//�ⷨ����:ɨ��A�����ÿ��Ԫ�أ������Ԫ�ز���0��A[i][j] != 0,��ô��Ԫ�����ڵ�i�п��Ժ�B�����ÿһ����ˣ�
//         Ҳ����˵��A[i][j]Ԫ�ؿ��Ժ�B[j][k]��ˣ��������ջ�ӵ�C[i][k]Ԫ���С�

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B)
{
	int m = A.size();
	int n = B.size();
	int p = B[0].size();
	std::vector<std::vector<int>> C(m, std::vector<int>(p, 0));//C�����ʼ����0

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (A[i][j])//����0����ʾA[i][j]���Ժ�ÿһ��B[j][k]���
			{
				for (int k = 0; k < p; ++k)
					C[i][k] += A[i][j] * B[j][k];
			}
		}
	}
	return C;
}