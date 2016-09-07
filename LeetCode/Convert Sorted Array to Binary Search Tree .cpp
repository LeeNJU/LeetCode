#include<vector>
#include"TreeNode.h"
//题目描述：给定一个已排序的数组，把这个数组转换成高度平衡的二叉树
//解法描述：要转换成高度平衡的二叉树，两边尽可能平均，因此对每一个数组，选中间元素作为根节点，因而分成两个子数组，每个子数组递归转换，子数组的根节点作为
//根节点的左右子节点

TreeNode* build(int first, int last, const std::vector<int>& num)//first和last为数组下标
{
	if (first > last)
		return nullptr;

	int middle = (first + last) / 2;//选中间元素作为根节点
	TreeNode* root = new TreeNode(num[middle]);

	root->left = build(first, middle - 1, num);//对两个子数组递归调用，生成子数组的根节点，作为左右子节点
	root->right = build(middle + 1, last, num);

	return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& num)
{
	return build(0, num.size() - 1, num);
}