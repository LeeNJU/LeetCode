#include<vector>
#include<queue>
#include"TreeNode.h"
#include<unordered_map>
//��Ŀ����:����һ����������������Ĵ�ֱ���������������Ϊ[3,9,20,4,5,2,7]����ô��ֱ����Ϊ[[4],[9],[3, 5, 2],[20],[7]]
//�ⷨ����:���ڵ��col�����ӽڵ��col��1�������ӽڵ��colС1�����в�α���������ÿ�����col��������map�洢ÿ��col�Ľڵ�
std::vector<std::vector<int>> verticalOrder(TreeNode* root) 
{
	std::unordered_map<int, std::vector<int>> mp;//��ͬһ��col����Ľڵ�
	std::queue<std::pair<TreeNode*, int>> q;
	std::vector<std::vector<int>> res;
	if (!root) 
		return res;
	
	q.push(std::make_pair(root, 0));
	while (!q.empty())
	{
		TreeNode* current = q.front().first;
		int index = q.front().second;
		q.pop();
		mp[index].push_back(current->val);
		if (current->left)//���ӽڵ��col�ȵ�ǰ���ڵ�С1
			q.push(std::make_pair(current->left, index - 1));
		if (current->right)
			q.push(std::make_pair(current->right, index + 1));
	}
	
	for (auto m : mp)
		res.push_back(m.second);
	
	return res;
}