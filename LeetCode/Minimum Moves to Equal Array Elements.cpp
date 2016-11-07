#include<vector>
#include<algorithm>
//题目描述:给定一个数组，定义一个move操作，move操作把数组中的n - 1个元素增加1或者减少1，求最少需要多少个move
//        操作，可以使得数组中的元素全部相等。例如[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4].最少需要
//        3个操作
//解法秒速:对n - 1个元素加1，相当于对最大的元素减1，先找到最小的元素，然后累加其他元素与最小元素的差

int minMoves(std::vector<int>& nums) 
{
	if (nums.size() <= 1)
		return 0;

	int min = *min_element(nums.begin(), nums.end());
	int count = 0;
	for (int val : nums)
		count += (val - min);

	return count;
}