#include<vector>
#include"TreeNode.h"
//��Ŀ����:����һ������n����ʾ��n������1��2��3��..., n,����Щ���������bianry search tree,���ܹ��ж�����Ψһ
//        ��BST
//�ⷨ����:��̬�滮����iΪ���ڵ㣬1��i - 1Ϊ��������i + 1��nΪ���ӽڵ㣬�������ܱ�֤����Ψһ�ԡ�
//         ���n = 0��dp[0] = 1,ֻ��һ�ֿ�����dp[1] = 1,ֻ��һ���㣬dp[2] = dp[0] * dp[2 - 1](1Ϊ���ڵ�) + 
//        dp[1] * dp[2 - 2](2Ϊ���ڵ�)�� dp[i] += dp[k - 1] * dp[i - k], 1 <= k <= i. dp[i]��ʾ��i������
//        ������ɶ��ٸ�BST��dp[k - 1]��ʾ��kΪ���ڵ㣬��k - 1����������ɶ��ٸ�BST��dp[i - k]��ʾ����k������
//        ֮�󣬻�ʣi - k�����֣�����ɶ��ٸ�BST

int numTrees(int n) 
{
	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) 
	{
		for (int k = 1; k <= i; ++k)
			dp[i] += dp[k - 1] * dp[i - k];
	}

	return dp[n];
}

//Ҫ��������п��ܵ�BST
//�ⷨ����:�ݹ飬genTree��ʾ����������iΪ���ڵ������start <= i <= end,
std::vector<TreeNode*> genTree(int start, int end)
{
	std::vector<TreeNode*> vec;
	if (start > end)//start����end������nullptr
	{
		vec.push_back(nullptr);
		return vec;
	}

	for (int i = start; i <= end; ++i)//��iΪ���ڵ�
	{

		std::vector<TreeNode*> left = genTree(start, i - 1);//���ش�start��i - 1Ϊ���ڵ����
		std::vector<TreeNode*> right = genTree(i + 1, end);

		for (int j = 0; j < left.size(); ++j)//���������������еĿ��ܽ������
		{
			for (int k = 0; k < right.size(); ++k)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left[j];
				root->right = right[k];
				vec.push_back(root);
			}
		}
	}

	return vec;
}

std::vector<TreeNode*> generateTrees(int n)
{
	if (n < 1)
		return std::vector<TreeNode*>();
	return genTree(1, n);
}