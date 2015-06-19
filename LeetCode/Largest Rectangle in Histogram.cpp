#include<vector>
#include<stack>
#include<algorithm>
//题目描述：给定一个数组，包含非负整数，表示每个长方形的高度，宽度都是1，求这些长方形的最大面积
//解法描述：用一个栈记录长方形长度的下标，如果当前元素比栈顶下标的长方形高度高或者栈为空，那么下标入栈，得到递增的下标序列，如果当前高度比栈顶的长方形
//         高度低，找到前面第一个比当前高度低的长方形，计算这两个长方形之间的长方形的面积（不包括这两个长方形）

int largestRectangleArea(std::vector<int>& height)
{
	int area = 0;
	std::stack<int> stack;
	for (int i = 0; i < height.size(); ++i) 
	{
		if (stack.empty() || height[stack.top()] < height[i]) //空栈或者是递增序列，那么入栈
			stack.push(i);
		else 
		{
			int start = stack.top(); //弹出栈顶元素，计算面积
			stack.pop();
			int width = stack.empty() ? i : i - stack.top() - 1;
			area = std::max(area, height[start] * width);
			i--;  //注意这里i--，是为了计算前面的长方形面积，逐一进行计算
		}
	}
	while (!stack.empty()) //栈不为空，说明数组最后的几个元素刚好是递增序列，那么依次计算
	{
		int start = stack.top();
		stack.pop();
		int width = stack.empty() ? height.size() : height.size() - stack.top() - 1;
		area = std::max(area, height[start] * width);
	}
	return area;
}