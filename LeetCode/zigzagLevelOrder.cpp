#include<vector>
#include<queue>
#include"TreeNode.h"

//��Ŀ����������һ����������������zigzag��ʽ�Ĳ�α����������ż����ı������Ҫ��תһ��
//�ⷨ�����������ǲ�α��������Ǽ�һ���������ÿһ���Ƿ���Ҫ��ת����ÿһ��Ľ�β������һ��nullptr��Ϊ�����֮��ķָ���

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (nullptr == root) 
		return result;
	
	std::queue<TreeNode*> q;
	bool left_to_right = true; //���������¼�ò��Ǵ����һ��Ǵ��ҵ���
	std::vector<int> level; //����ĳһ�������
	q.push(root);
	q.push(nullptr); //�������Ҫ������һ��nullptr��Ϊ�����֮��ķָ�
	while (!q.empty()) 
	{
		TreeNode *cur = q.front();
		q.pop();
		if (cur) //����һ�������
		{
			level.push_back(cur->val);
			if (cur->left) 
				q.push(cur->left);
			if (cur->right) 
				q.push(cur->right);
		}
		else //һ�������
		{
			if (!left_to_right)//����left_to_right�ж��Ƿ���Ҫ��ת
				reverse(level.begin(), level.end());
			result.push_back(level);

			level.clear();
			left_to_right = !left_to_right;
			if (q.size() > 0) //ע�������q��Ϊ�յ�ʱ�򣬲Ű�nullptr����q��˵��q���滹�зǿ�Ԫ�ء������ʱqΪ�գ�˵��ѭ���ý����ˣ���Ӧ���ټ���
				q.push(nullptr);//������Ԫ�أ���������
		}
	}
	return result;
}