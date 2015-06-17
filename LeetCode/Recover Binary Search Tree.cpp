#include"TreeNode.h"
#include<vector>
//��Ŀ����������һ�ö������������������ڵ㱻�����ˣ��ҵ��������ڵ㲢�ָ��������Ľṹ
//�ⷨ��������morris��������ķ�ʽ�������������һ�߱�����һ�߼���Ƿ���϶������ṹ��ע�⽻���Ľڵ���������ڵģ�Ҳ���ܲ������ڵ�

void detect(std::pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current) 
{
	if (prev != nullptr && prev->val > current->val) //���prev��ֵ��current��ֵ��˵���ҵ�һ���ڵ�
	{
		if (broken.first == nullptr) //�п��������ڵĽڵ㱻�������п��ܲ������ڵĽڵ㱻����
		{
			broken.first = prev;
		} 
		broken.second = current;
	}
}

void recoverTree(TreeNode* root)
{
	std::pair<TreeNode*, TreeNode*> broken;
	TreeNode* prev = nullptr;
	TreeNode* cur = root;
	while (cur)  //morris�������
	{
		if (cur->left == nullptr)
		{
			detect(broken, prev, cur);
			prev = cur;
			cur = cur->right;
		}
		else
		{
			TreeNode* temp = cur->left;
			while (temp->right != nullptr && temp->right != cur)
				temp = temp->right;

			if (temp->right == nullptr)
			{
				temp->right = cur;
				cur = cur->left;
			}
			else
			{
				detect(broken, prev, cur);
				prev = cur;
				temp->right = nullptr;
				cur = cur->right;
			}
		}
	}

	std::swap(broken.first->val, broken.second->val);
}