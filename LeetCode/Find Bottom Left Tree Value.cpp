#include"TreeNode.h"
#include<queue>
#include<vector>
//��Ŀ����:����һ�����������ҵ����һ��ĵ�һ��Ԫ�أ�����
//                    2
//                 1     3   ���һ��ĵ�һ��Ԫ����1
//�ⷨ����:��α�����ֻ��Ҫ��¼ÿһ��ĵ�һ��Ԫ�ؾ�����

int findBottomLeftValue(TreeNode* root) 
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	queue.push(nullptr);

	std::vector<int> vec;
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();

		if (node != nullptr)
		{
			if (vec.empty())//����vec�Ƿ�Ϊ�����ж��ǲ��ǵ�һ��Ԫ��
				vec.push_back(node->val);
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
		}
		else
		{
			if (!queue.empty())
			{
				vec.clear();
				queue.push(nullptr);
			}
		}
	}

	return vec.front();
}