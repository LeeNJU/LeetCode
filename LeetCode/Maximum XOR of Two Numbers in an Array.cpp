#include<vector>
#include<unordered_set>
//题目描述:给定一个整数数组，找到两个数，使得它们进行异或操作的结果最大，例如给定数组[3, 10, 5, 25, 2, 8]，
//        最大的异或结果是5 ^ 25 = 28，返回28
//解法描述:从最高位开始，用mask分割数组中的元素

int findMaximumXOR(std::vector<int>& nums)
{
	int max_val = 0, mask = 0;
	for (int i = 31; i >= 0; i--) 
	{
		mask |= (1 << i);//mask用来把数组里的元素根据第i位的值进行分割
		std::unordered_set<int> set;
		for (int num : nums) 
			set.insert(num & mask); // 保存最左边的位，mask刚开始为1，然后是11，然后是111，然后是1111...

		int tmp = max_val | (1 << i); //找到是否存在两个数字a和b，在第i位上是不同的，并且a ^ b = temp
		for (int prefix : set) 
		{
			if (set.find(tmp ^ prefix) != set.end()) 
				max_val = tmp;
		}
	}
	return max_val;
}