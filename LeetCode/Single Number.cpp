#include<vector>
//题目描述:给定一个数组，数组中的元素都会出现2次，只有其中一个元素只出现1次，找出这个元素
//解法解法:对每个元素进行异或操作，因为出现2次的元素进行异或之后每一位等于0，再与剩下的元素进行异或，
//        结果不变，最终结果就是它

int singleNumber(std::vector<int>& nums) 
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= nums[i];
	return result;
}

//题目描述:给定一个数组，里面每一个数都出现3次，只有一个数出现1次，找到这个只出现1次的数
//解法描述:one表示到当前变量为止，二进制中1出现1次的有哪些位，two表示到当前变量为止，二进制中1出现2次的
//         有哪些位

int singleNumber2(std::vector<int>& nums)
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

//题目描述：给定一个数组，其中有两个数只出现一次，其余的树出现两次，找到这两个数
//解法描述：先对所有的数进行异或操作，得到的结果等于x和y进行异或的结果，由于x和y不可能相等，结果中必然有一位
//         等于1,从右边开始找，找到等于1的那一位，然后以此把数组中的数分成两个部分，x和y分别在这两个部分中，
//         对这两个部分的数进行异或，得到x和y

std::vector<int> singleNumber3(std::vector<int>& nums)
{
	std::vector<int> result(2, 0);
	int n = 0;
	for (int i = 0; i < nums.size(); ++i)//所有的数进行异或操作，异或的结果为x和y进行异或的结果
		n ^= nums[i];

	int index = 0; //从右边开始找第一个为1的位
	while (n % 2 == 0)
	{
		n = n >> 1;
		++index;
	}
	for (int i = 0; i < nums.size(); ++i)//根据这一位是否为1把数组分成两个部分
	{
		if ((nums[i] >> index) % 2 == 0)
			result[0] ^= nums[i];
		else
			result[1] ^= nums[i];
	}
	return result;
}