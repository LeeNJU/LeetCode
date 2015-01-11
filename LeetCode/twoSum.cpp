#include<vector>
#include<algorithm>
#include<unordered_map>

//题目描述：给定一个数组，从中间找出2个数使其加起来等于指定的一个数，例如array={2,9,33,1}找出和等于11的2个数
//解法：用unordered_map存每个数的下标，时间复杂度为O(n)

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
	std::vector<int> result;
	std::unordered_map<int, int> map;

	for (int i = 0; i < numbers.size(); ++i)//用hash表存每个数的下标
		map[numbers[i]] = i;

	for (int i = 0; i < numbers.size(); ++i)
	{
		std::unordered_map<int, int>::iterator iter = map.find(target - numbers[i]);
		if (iter != map.end())//在hash表中查找元素，复杂度为常数级
		{
			if (iter->second == i)//找到了同一个元素，例如array={3,2,4}中找和等于6的2个数，防止重复找到3
				continue;

			result.push_back(i + 1);
			result.push_back(map[target - numbers[i]] + 1);
			break;
		}
	}
	return result;
}

