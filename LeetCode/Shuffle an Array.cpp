#include<vector>
//题目描述:给定一个数组，对其进行打乱重排，使得每一种排列的可能性都是相同的。
//解法描述:采用随机数发生器，对第i个位置的元素，产生一个随机下标，得到这个位置的元素，i加1，随机数的范围随之
//        减小。

class Solution 
{
private:
	std::vector<int> vec;
public:
	Solution(std::vector<int> nums) 
	{
		this->vec = nums;
	}

	/** Resets the array to its original configuration and return it. */
	std::vector<int> reset() 
	{
		return vec;
	}

	/** Returns a random shuffling of the array. */
	std::vector<int> shuffle() 
	{
		std::vector<int> result(vec);
		for (int i = 0; i < vec.size(); ++i)
		{
			int index = rand() % (vec.size() - i);//随机数的范围随之减小
			std::swap(result[i], result[i + index]);//得到随机下标，将当前元素与之交换
		}
		return result;
	}
};