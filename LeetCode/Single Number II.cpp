#include<vector>
//题目描述：给定一个数组，里面每一个数都出现3次，只有一个数出现1次，找到这个只出现1次的数
//解法描述：one表示到当前变量为止，二进制中1出现1次的有哪些位，two表示到当前变量为止，二进制中1出现2次的有哪些位

int singleNumber(std::vector<int>& nums) 
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); ++i) 
	{
		two |= (one & nums[i]);  //two保存1出现2次的每一位
		one ^= nums[i]; // one保存1出现1次的每一位
		three = ~(one & two);
		one &= three; //three中出现3次的位被置为0，在one和two中这些位也应该被置为0
		two &= three;
	}
	return one;
}