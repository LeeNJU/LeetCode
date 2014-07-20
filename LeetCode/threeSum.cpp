#include<vector>
#include<algorithm>


void twoSum(std::vector<std::vector<int>>& result, std::vector<int> num, int index, int target)
{
	std::vector<int> vec;
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
			if (index <= first)
			{
				vec.push_back(num[index]);
				vec.push_back(num[first]);
				vec.push_back(num[last]);
			}
			else if (index > first && index <= last)
			{
				vec.push_back(num[first]);
				vec.push_back(num[index]);
				vec.push_back(num[last]);
			}
			else
			{
				vec.push_back(num[first]);
				vec.push_back(num[last]);
				vec.push_back(num[index]);
			}
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