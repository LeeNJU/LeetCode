#include"TreeNode.h"
#include<vector>
//题目描述：给定一个数字n，求出总共有多少种唯一的二叉树，每个二叉树存储1到n的值
//解法描述：递推公式 f(i) = Σ 1<=k<=i  f(k - 1) * f(i - k)

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