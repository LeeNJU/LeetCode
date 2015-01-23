#include<vector>
//题目描述：给定一个非负数组表示一个很大的数，给这个数加1
//解法：逆向迭代数组，注意进位和取模
std::vector<int> plusOne(std::vector<int> &digits)
{
	int carry = 1;
	for (std::vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ++iter)
	{
		*iter += carry;
		carry = *iter / 10;//向前进位
		*iter %= 10;//取模
	}
	if (carry > 0)
		digits.insert(digits.begin(), 1);

	return digits;
}