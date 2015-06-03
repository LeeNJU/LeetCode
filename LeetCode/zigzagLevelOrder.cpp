#include<vector>
#include<queue>
#include"TreeNode.h"

//题目描述：给定一个二叉树，返回用zigzag方式的层次遍历结果，即偶数层的遍历结果要反转一下
//解法描述：本质是层次遍历，但是加一个变量标记每一层是否需要反转，在每一层的结尾，加入一个nullptr作为层与层之间的分隔符

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (nullptr == root) 
		return result;
	
	std::queue<TreeNode*> q;
	bool left_to_right = true; //这个变量记录该层是从左到右还是从右到左
	std::vector<int> level; //保存某一层的数据
	q.push(root);
	q.push(nullptr); //这个很重要，加入一个nullptr作为层与层之间的分割
	while (!q.empty()) 
	{
		TreeNode *cur = q.front();
		q.pop();
		if (cur) //保存一层的数据
		{
			level.push_back(cur->val);
			if (cur->left) 
				q.push(cur->left);
			if (cur->right) 
				q.push(cur->right);
		}
		else //一层结束了
		{
			if (!left_to_right)//根据left_to_right判断是否需要反转
				reverse(level.begin(), level.end());
			result.push_back(level);

			level.clear();
			left_to_right = !left_to_right;
			if (q.size() > 0) //注意这里，当q不为空的时候，才把nullptr加入q，说明q里面还有非空元素。如果此时q为空，说明循环该结束了，不应该再加入
				q.push(nullptr);//其他的元素，否则会出错
		}
	}
	return result;
}