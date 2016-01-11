#include<vector>
//题目描述:给定一个二叉搜索树的先序遍历，判断是不是有效的先序遍历
//解法描述:利用二叉搜索书的先序遍历，用数组模拟栈，碰到降序，把元素放到栈中，碰到升序元素，即碰到二叉搜索树中
//        某个右节点，在栈中找到比当前元素小的元素作为lowerBound，因为之后的元素都要比lowerBound大，如果某个
//        元素比lowerBound小，说明不是先序遍历

bool verifyPreorder(std::vector<int>& preorder) 
{
	if (preorder.empty()) 
		return true;
	
	int lowerBound = INT_MIN;
	int stackTopPosition = 0;
	for (int pos = 1; pos < preorder.size(); ++pos) 
	{
		if (preorder[pos] < lowerBound) 
			return false;
		while (stackTopPosition >= 0 && preorder[pos] > preorder[stackTopPosition]) 
			lowerBound = preorder[stackTopPosition--];  //更新lowerBound
		
		preorder[++stackTopPosition] = preorder[pos];  //降序，压入栈中
	}
	return true;
}