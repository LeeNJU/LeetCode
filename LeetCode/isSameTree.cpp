#include"TreeNode.h"
using namespace std;



bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;

	if (p == nullptr || q == nullptr)
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
