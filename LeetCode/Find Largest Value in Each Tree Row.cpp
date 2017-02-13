#include<vector>
#include<queue>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����:����һ�����������ҵ�ÿһ������Ԫ�أ�����
//                     1
//                 3        2
//            5        3        9
//         ��ôÿһ������Ԫ�طֱ���[1,3,9]
//�ⷨ����:��α���������ÿһ������Ԫ��

std::vector<int> largestValues(TreeNode* root)
{
	if (root == nullptr)
		return std::vector<int>();

	std::queue<TreeNode*> queue;
	queue.push(root);
	queue.push(nullptr);

	std::vector<int> result;
	int max_val = INT_MIN;
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();

		if (node)
		{
			max_val = std::max(max_val, node->val);
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
		}
		else
		{
			result.push_back(max_val);
			if (!queue.empty())
			{
				max_val = INT_MIN;
				queue.push(nullptr);
			}
		}
	}

	return result;