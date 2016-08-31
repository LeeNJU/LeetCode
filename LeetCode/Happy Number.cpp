#include<unordered_set>
//题目描述:给定一个整数n，判断是否是happy number， 例如19是happy number：
//解法描述:用哈希set保存中间算出的值
bool isHappy(int n)
{
	std::unordered_set<int> s;
	while (s.find(n) == s.end())
	{
		s.insert(n);
		int value = 0;
		while (n)
		{
			int digit = n % 10;
			n /= 10;
			value += digit * digit;
		}
		n = value;
		if (n == 1)
			return true;
	}
	return false;
}