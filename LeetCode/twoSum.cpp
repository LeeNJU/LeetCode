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


//version 2
//数组已排好序，找两个元素，使得它们的和等于target
std::vector<int> twoSum2(std::vector<int> &numbers, int target)
{
	std::vector<int> result(2,0);
	int left = 0, right = numbers.size() - 1;
	while (left < right)
	{
		if (numbers[left] + numbers[right] == target)
		{
			result[0] = left + 1;
			result[1] = right + 1;
			return result;
		}
		else if (numbers[left] + numbers[right] < target)
			++left;
		else
			--right;
	}
	return result;
}

//version 3
//设计一个类，有两个操作，add和find，add添加一个数，find找到两个数，使得它们的和等于给定的参数
//解法描述:用一个map保存每个元素以及出现的次数(因为可能有重复元素)，然后利用map进行查找
class TwoSum 
{
private:
	std::unordered_map<int, int> elemCount;

public:
	void add(int number) 
	{
		elemCount[number]++;
	}

	bool find(int value) 
	{
		for (auto elem : elemCount) 
		{
			if ((elem.first < value - elem.first && elemCount.count(value - elem.first)) ||
				(elem.first == value - elem.first && elem.second > 1))
				return true;
		}
		return false;
	}
};
