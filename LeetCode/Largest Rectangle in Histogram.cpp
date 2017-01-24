#include<vector>
#include<stack>
#include<algorithm>
//题目描述:给定一个数组，包含非负整数，表示每个长方形的高度，宽度都是1，求这些长方形的最大面积
//解法描述:用一个栈记录长方形长度的下标，如果当前元素比栈顶下标的长方形高度高或者栈为空，那么下标入栈，得到
//        递增的下标序列，如果当前高度比栈顶的长方形高度低，找到前面第一个比当前高度低的长方形，计算这两个长
//        方形之间的长方形的面积（不包括这两个长方形）
//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html

int largestRectangleArea(std::vector<int>& heights)
{
	std::stack<int> stack;
	heights.push_back(0);//插入高度为0的bar，是为了计算最后的递增序列的面积

	int sum = 0;
	int i = 0;
	while (i < heights.size())
	{
		if (stack.empty() || heights[i] > heights[stack.top()]) //当前高度比栈顶元素小或者栈为空
		{
			stack.push(i);
			++i;
		}
		else
		{
			while (!stack.empty() && heights[stack.top()] >= heights[i])//统计之前的递增序列形成的最大面积
			{
				int t = stack.top();//注意这里，高度是用heights[t]
				stack.pop();
				sum = std::max(sum, heights[t] * (stack.empty() ? i : i - stack.top() - 1));
			}

			stack.push(i);
			++i;
		}
	}
	return sum;
}