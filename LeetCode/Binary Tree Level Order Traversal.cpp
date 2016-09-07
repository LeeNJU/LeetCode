#include<vector>
#include<queue>
#include"TreeNode.h"

//��Ŀ��������α���������������һ����ά����
//�ⷨ�������ö��в�α����������м���nullptr��Ϊ�����֮��ķָ���

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (!root)
		return result;

	std::queue<TreeNode*> q;
	std::vector<int> level;
	q.push(root);
	q.push(nullptr);//nullptr��Ϊ�����֮��ķָ���

	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();
		if (node)//��ǰ���Ƿָ����ǽڵ�
		{
			level.push_back(node->val);
			if (node->left)//�������ҽڵ�
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		else//�ָ���
		{
			result.push_back(level);
			level.clear();//���level
			if (!q.empty())//ע�⣬��q��Ϊ�յ�����²��ܼ���nullptr�ָ���
				q.push(nullptr);
		}
	}
	return result;
}

//��Ŀ��������α���һ����������ÿһ���Ԫ����һ�����鱣�棬����һ����ά���飬�����Ե�����
//�ⷨ��������α��������תһ��

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (!root)
		return result;

	std::queue<TreeNode*> q;
	std::vector<int> level;
	q.push(root);
	q.push(nullptr);//nullptr��Ϊ�����֮��ķָ���

	while (!q.empty())
	{
		TreeNode* node = q.front();
		q.pop();
		if (node)//��ǰ���Ƿָ����ǽڵ�
		{
			level.push_back(node->val);
			if (node->left)//�������ҽڵ�
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		else//�ָ���
		{
			result.push_back(level);
			level.clear();//���level
			if (!q.empty())//ע�⣬��q��Ϊ�յ�����²��ܼ���nullptr�ָ���
				q.push(nullptr);
		}
	}
	reverse(result.begin(), result.end());//��תһ��
	return result;
}