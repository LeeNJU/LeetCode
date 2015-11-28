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

//version 2
//��Ŀ����������һ��n���ҵ����з��������Ķ���������
//�ⷨ����:�ݹ飬�������߽�

std::vector<TreeNode*> dfs(int left, int right)
{
	std::vector<TreeNode*> result;
	if (left < right)
	{
		result.push_back(nullptr);
		return result;
	}

	for (int i = left; i <= right; ++i)
	{
		std::vector<TreeNode*> left_sub_tree = dfs(left, i - 1);
		std::vector<TreeNode*> right_sub_tree = dfs(i + 1, right);
		for (int j = 0; j < left_sub_tree.size(); ++j)
		{
			for (int k = 0; k < right_sub_tree.size(); ++k)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left_sub_tree[j];
				root->right = right_sub_tree[k];
				result.push_back(root);
			}
		}
	}
	return result;
}

std::vector<TreeNode*> generateTrees(int n) 
{
	return dfs(1, n);
}