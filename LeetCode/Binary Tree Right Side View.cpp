#include"TreeNode.h"
#include<vector>
#include<queue>

//��Ŀ����������һ��������������վ����������ұߣ��ҵ����ܿ�����Ԫ�أ��������ÿһ������ұߵ�Ԫ��
//�ⷨ����:��α�������������null���ָ�������һ��������¼ÿһ���Ԫ�أ�������null�ָ�����ʱ���������������һ������ұߵ�Ԫ��

std::vector<int> rightSideView(TreeNode* root)
{
	std::vector<int> result;
	if (root == nullptr)
		return result;

	std::queue<TreeNode*> q;
	q.push(root);
	q.push(nullptr);//nullΪ�����֮��ķָ���
	int value = 0;//value��¼��һ�����ұߵ�Ԫ��
	while (!q.empty())
	{
		TreeNode* p = q.front();
		q.pop();
		if (p != nullptr)
		{
			value = p->val;
			if (p->left)//ѹ����������������
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}
		else
		{
			result.push_back(value);
			if (!q.empty())
				q.push(nullptr);//ѹ��null��Ϊ��ָ���
		}
	}
	return result;
}