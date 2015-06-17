#include<vector>

//题目描述：给定一个值n，求出n位的gray code，相邻两个gray code在二进制表示上只在一位上有差别，例如n = 2，gray code为00， 01， 11，10
//解法描述：找规律即可，n为的gray code由两部分组成，一部分是n-1位格雷码，再加上 1<<(n-1)和n-1位格雷码的逆序的和

std::vector<int> grayCode(int n)
{
	std::vector<int> result;
	result.push_back(0);
	for (int i = 0; i < n; i++) 
	{
		const int highest_bit = 1 << i;
		for (int j = result.size() - 1; j >= 0; j--) // 要反着遍历，才能对称
			result.push_back(highest_bit | result[j]);
	}
	return result;
}