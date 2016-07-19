#include"TreeNode.h"
#include<algorithm>
//��Ŀ����:����һ�����������ҵ����а��������Ķ�����������Ҳ���ڵ����
//�ⷨ����:�ݹ飬���ڵ�ǰ�ڵ㣬���浱ǰ�ڵ���Ϊ�����������ֵ����Ϊ����������Сֵ�����������������Ͻ��еݹ顣

bool isValidBST(TreeNode* root, int& mn, int& mx, int& result) 
{
	if (!root) 
		return true;
    
	int left_n = 0, right_n = 0, left_mn = INT_MIN;
	int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
	bool left = isValidBST(root->left, left_mn, left_mx, left_n);
	bool right = isValidBST(root->right, right_mn, right_mx, right_n);
	
	if (left && right) //��������ͬʱ����
	{
		if ((!root->left || root->val >= left_mx) && (!root->right || root->val <= right_mn)) 
		{   //�ҵ�һ������������
			result = left_n + right_n + 1;
			mn = root->left ? left_mn : root->val;
			mx = root->right ? right_mx : root->val;
			return true;
		}
	}
	result = std::max(left_n, right_n);
	return false;
}
int largestBSTSubtree(TreeNode* root)
{
	int result = 0, mn = INT_MIN, mx = INT_MAX;
	bool d = isValidBST(root, mn, mx, result);
	return result;
}