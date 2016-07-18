#include"TreeNode.h"
#include<vector>
//题目描述:给定一个嵌套的链表，求出元素的和，例如[1,[4,[6]]]返回27，因为1的深度是1,4的深度是2,6的深度是3，所以
//        和是1 * 1 + 2 * 4 + 6 * 3 = 27.
//解法描述:递归，判断当前元素是否是一个整数还是一个链表，然后根据深度求和

int dfs(std::vector<NestedInteger>& nestedList, int depth) 
{
	int sum = 0;
	for (auto  element : nestedList) 
		sum += element.isInteger() ? element.getInteger() * depth : dfs(element.getList(), depth + 1);
	return sum;
}

int depthSum(std::vector<NestedInteger>& nestedList) 
{
	return dfs(nestedList, 1);
}
