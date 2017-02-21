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

//版本2:给定一个数组，现有有一个move操作，可以把一个元素加1或者减1，求最少需要多少个move操作，使得数组中的元素
//      全部相等，例如[1,2,3],需要2个move操作,所有元素变成2
//解法描述:排序，找到中间的元素，把所有元素变成中间的元素，记录每个元素与中间的差，然后求和

int minMoves2(std::vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	int median = nums[nums.size() / 2];

	int sum = 0;
	for (int val : nums)
		sum += abs(val - median);
	return sum;
}