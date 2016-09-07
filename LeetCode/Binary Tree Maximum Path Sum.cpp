#include"TreeNode.h"
#include<algorithm>
//��Ŀ����:����һ�����������ҵ�����·���ͣ�������ʼ�����������ڵ㣬��ֹ�ڵ�Ҳ����������ڵ㡣���Ǳ�������
//         parent-child��ϵ
//�ⷨ����:���Ž���ܴ�����ĳ����������(�ֲ���)��������result���á� ��������һ���ڵ㣬��4���������������·����������
//         ��·�����ڵ㱾���Լ���������·�� + �ڵ㱾�� + ��������·��
int findMax(TreeNode* root, int& result)
{
	if (root == nullptr)
		return 0;

	int left_sub = findMax(root->left, result); //�������ӽڵ�Ϊ����·��֮��
	int right_sub = findMax(root->right, result); //�������ӽڵ�Ϊ����·��֮��
	int max_sum = std::max(std::max(left_sub, right_sub) + root->val, root->val); //�Ƚ�������ֵ
	result = std::max(std::max(root->val + left_sub + right_sub, max_sum), result);
	return  max_sum; //ע��������ص�����·��֮�ͣ���·��֮�ͣ���ǰ�ڵ�֮������ֵ����������·�� + ��·�� + ��ǰ
	                 //�ڵ�
}
int maxPathSum(TreeNode* root) 
{
	int result = INT_MIN;
	findMax(root, result);
	return result;

}