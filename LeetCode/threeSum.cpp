#include<vector>
#include<algorithm>


void twoSum(std::vector<std::vector<int>>& result, std::vector<int> num, int index, int target)
{
	std::vector<int> vec(3);
	int first = 0, last = num.size() - 1;
	while (first < last)
	{
		if (first == index)
		{
			++first;
			continue;
		}
		if (last == index)
		{
			--last;
			continue;
		}

		if (num[first] + num[last] > target)
			--last;
		else if (num[first] + num[last] < target)
			++first;
		else
		{
			vec.push_back(num[index]);
			vec.push_back(num[first]);
			vec.push_back(num[last]);
			sort(vec.begin(), vec.end());
			result.push_back(vec);
		}
	}
}

std::vector<std::vector<int>> threeSum(std::vector<int>& num)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	for (size_t i = 0; i < num.size(); ++i)
	{
		twoSum(result, num, i, -num[i]);
	}
	return result;
}