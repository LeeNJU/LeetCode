#include<vector>
#include<algorithm>
#include <iostream>

void twoSum(std::vector<std::vector<int>>& result, const std::vector<int>& num, int index, int target)
{
	std::vector<int> vec;
	int first = index + 1, last = num.size() - 1;//first为index+1是为了防止同一个组合中的数字重复计算
	while (first < last)
	{
		if (num[first] + num[last] > target)
			--last;
		else if (num[first] + num[last] < target)
			++first;
		else
		{
			vec.push_back(num[index]);
			vec.push_back(num[first]);
			vec.push_back(num[last]);
			std::cout << num[index] << " " << num[first] << " " << num[last] << std::endl;
			result.push_back(vec);
			vec.clear();
			++first;
			--last;
			while (first < last && num[first] == num[first - 1])
				++first;
			while (first < last && num[last] == num[last + 1])
				--last;
		}
	}
}

std::vector<std::vector<int>> threeSum(std::vector<int>& num)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	for (int i = 0; i < (int)num.size() - 2; ++i)//num.size返回的是无符号类型，无符号类型0减去一个数，结果不是负数，会变大
	{
		if (i != 0 && num[i] == num[i - 1])
			continue;
		twoSum(result, num, i, -num[i]);
	}
	return result;
}
int main()
{
	std::vector<int> vec = {-1, 0, 1, 2, -1, -4};
	std::cout << threeSum(vec).size() << std::endl;
	return 0;
}