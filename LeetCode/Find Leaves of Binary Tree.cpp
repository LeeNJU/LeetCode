#include"TreeNode.h"
#include<vector>
//��Ŀ����:����һ�����������ҵ����е�Ҷ�ӽڵ㣬Ȼ��ɾ��Ҷ�ӽڵ㣬�õ�һ���µĶ�������Ȼ�����ҵ�����Ҷ�ӽڵ㲢
//        ɾ����ֱ����Ϊ�ա�����       1
//                                 2    3
//                               4   5
//        ���ؽ��Ϊ[[4,5,3], [2],[1]]
//�ⷨ����:�ݹ��ҵ�Ҷ�ӽڵ㣬Ȼ����Ϊnullptr

TreeNode* remove(TreeNode *node, std::vector<int>& leaves) //ÿ�ε��þ�ɾ��Ҷ�ӽڵ㣬����ʣ�����
{
	if (!node) 
		return nullptr;
	if (!node->left && !node->right) 
	{
		leaves.push_back(node->val);
		return nullptr;
	}
	node->left = remove(node->left, leaves);
	node->right = remove(node->right, leaves);
	return node;
}

std::vector<std::vector<int>> findLeaves(TreeNode* root) 
{
	std::vector<std::vector<int>> result;
	while (root) 
	{
		std::vector<int> leaves;
		root = remove(root, leaves);
		result.push_back(leaves);
	}
	return result;
}