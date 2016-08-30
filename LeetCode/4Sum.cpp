#include<vector>
#include<algorithm>

//题目描述:给定一个数组和一个值，从中找出四个数字，使得它们的和等于给定的值
//解法描述:先排序，两层for循环，确定头两个数字，然后用两个头尾指针向中间逼近，注意去重，复杂度O(n3)

std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;

	for (int i = 0; i < (int)num.size(); ++i)//第一层for循环，确定第一个数字
	{
		if (i > 0 && num[i] == num[i - 1])//防止重复
			continue;

		for (int j = i + 1; j < (int)num.size(); ++j)//第二层for循环，确定第二个数字
		{
			if (j > i + 1 && num[j] == num[j - 1])//防止重复
				continue;

			int left = j + 1, right = num.size() - 1;
			while (left < right)
			{
				if (left > j + 1 && num[left] == num[left - 1])//防止重复
				{
					++left;
					continue;
				}
				if (right < num.size() - 1 && num[right] == num[right + 1])//防止重复
				{
					--right;
					continue;
				}
				if (num[i] + num[j] + num[left] + num[right] == target)
				{
					result.push_back(std::vector<int>{num[i], num[j], num[left], num[right]});
					++left;
					--right;
				}
				else if (num[i] + num[j] + num[left] + num[right] < target)
					++left;
				else
					--right;
			}
		}
	}

	return result;
}