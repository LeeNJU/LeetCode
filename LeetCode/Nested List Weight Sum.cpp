#include"TreeNode.h"
#include<vector>
//题目描述:给定一个嵌套的链表，求出元素的和，例如[1,[4,[6]]]返回27，因为1的深度是1,4的深度是2,6的深度是3，所以
//        和是1 * 1 + 2 * 4 + 6 * 3 = 27.
//解法描述:递归，判断当前元素是否是一个整数还是一个链表，然后根据深度求和

int dfs(std::vector<NestedInteger>& nestedList, int depth) 
{
	int sum = 0;
	for (auto element : nestedList)
	{
		if (element.isInteger())
			sum += element.getInteger() * depth;
		else
		{
			std::vector<NestedInteger> t = element.getList();
			sum += dfs(t, depth + 1);
		}
	}
	return sum;
}

int depthSum(std::vector<NestedInteger>& nestedList) 
{
	return dfs(nestedList, 1);
}


//题目描述:权重反过来，最里面的元素权重为1，例如[[1,1],3,[1,1]]，1的权重是1,3的权重是2，所以和应该是2 * 3 + 
//        1 * 1 * 4 = 10
//解法描述:可以先求深度，然后用类似上一题的方法求解