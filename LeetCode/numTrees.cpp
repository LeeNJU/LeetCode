#include"TreeNode.h"
#include<vector>
//��Ŀ����������һ������n������ܹ��ж�����Ψһ�Ķ�������ÿ���������洢1��n��ֵ
//�ⷨ���������ƹ�ʽ f(i) = �� 1<=k<=i  f(k - 1) * f(i - k)

int numTrees(int n)
{
	std::vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k <= i; ++k)
			f[i] += f[k - 1] * f[i - k];
	}
	return f[n];
}