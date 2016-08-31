#include<vector>
#include<algorithm>
#include <iostream>

//题目描述：给定一个数字，从中找出三个数，使得它们的和等于0，返回下标
//解法：先排序，确定其中一个数，用两个头尾指针向中间逼近查找，复杂度O(n2)
//可能会有多种结果和重复结果，都要考虑，例如array={0,0,0,0}，答案应该是0,0,0一种

std::vector<std::vector<int>> threeSum(std::vector<int>& num)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	for (int i = 0; i < (int)num.size() - 2; ++i)//num.size() - 2,防止下标越界
	{
		if (i > 0 && num[i] == num[i - 1])//当元素i与元素i-1相等时，跳过
			continue;

		int value = -num[i], left = i + 1, right = num.size() - 1;
		while (left < right)//两个下标，从两头往中间逼近
		{
			if (left > i + 1 && num[left] == num[left - 1])//遇到重复元素时，跳过
			{
				++left;
				continue;
			}
			if (right < num.size() - 1 && num[right] == num[right + 1])//遇到重复元素时，跳过
			{
				--right;
				continue;
			}
			if (num[left] + num[right] > value)
				--right;
			else if (num[left] + num[right] < value)
				++left;
			else
			{
				result.push_back(std::vector<int> {num[i], num[left], num[right]});//找到一种结果
				++left;
				--right;
			}
		}
	}
	return result;
}