#include<vector>
//题目描述:给定一个数组大小为n + 1,每个元素都在1到n之间，那么其中必有重复元素，找到这个重复元素(不能修改数组)
//解法描述:二分法，在数组中找小于等于middle的个数，如果个数小于middle，那么重复元素一定在middle和right之间，
//        反之则在left和middle之间，注意这里的middle，left和right是真正要找的元素
int count_number(std::vector<int>& num, int value)
{
	int count = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i] <= value)
			++count;
	}
	return count;
}

int findDuplicate(std::vector<int>& nums)
{
	int left = 1, right = nums.size() - 1, middle = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		int count = count_number(nums, middle);
		if (count <= middle)
			left = middle + 1;
		else if (count > middle)
			right = middle;
	}
	return left;
}