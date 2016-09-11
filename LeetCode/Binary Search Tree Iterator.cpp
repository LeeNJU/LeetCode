#include"TreeNode.h"
#include<stack>

//��Ŀ����:ʵ��һ�������������ĵ�������������������next��hasNext��������������ƽ�����Ӷ�ΪO(1),�ռ临�Ӷ�Ϊ
//        O(h),����next������ָ����Ե�ǰ�ڵ�Ϊ���ڵ�Ķ�������������С��Ԫ�أ�������ߵĽڵ�
//�ⷨ����:��һ��ջ�����浱ǰ�ڵ���������ӽ�㣬����next����һ���ڵ��ʱ������ýڵ�����ӽڵ㲻Ϊ�գ���
//        �����������ӽ��ѹ��ջ��

class BSTIterator 
{
private:
	std::stack<TreeNode*> s; //ջs�������浱ǰ�ڵ�����ӽ��
public:
	BSTIterator(TreeNode *root) 
	{
		TreeNode* cur = root;  //�������ӽ��ѹ��ջ��
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() 
	{
		TreeNode* top = s.top();
		s.pop();
		int result = top->val;
		top = top->right;
		while (top) //�����������ӽڵ�ѹ��ջ��
		{
			s.push(top);
			top = top->left;
		}
		return result;
	}
};