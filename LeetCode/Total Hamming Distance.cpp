#include<vector>
//题目描述:给定一个整数数组，求出每两个数之间的hemming distance，例如[4, 14, 2],两两之间的hemming distance
//        是(4, 14) + (4, 2) + (14, 2) = 2 + 2 + 2 = 6.Hemming disance是位数不同的个数
//解法描述:对每个数的第i位，统计有多少个0，多少个1，n个0，m个1，那么就有n * m个hemming distance

int totalHammingDistance(std::vector<int>& nums) 
{
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		int bit_count = 0;
		for (int j = 0; j < nums.size(); ++j)
		{
			bit_count += ((nums[j] >> i) & 1);
		}

		result += bit_count * (nums.size() - bit_count);
	}
	return result;
}