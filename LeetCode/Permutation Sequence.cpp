#include<string>
#include<vector>

//题目描述：给定一个值n和k，求出123..n的第k个阶乘
//解法描述：注意数学公式， a1，a2,a3,... an, a1 = k / (n - 1)!, k2 = k % (n - 1)!, 依次把k / (n - 1)!的值加入到结果中

int factorial(int n) // n的阶乘
{
	int result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

std::string kth_permutation(const std::string& seq, int k) 
{
	const int n = seq.size();
	std::string S(seq);
	std::string result;
	int base = factorial(n - 1);
	--k; // 康托编码从0 开始
	for (int i = n - 1; i > 0; k %= base, base /= i, --i) // 从n - 1开始，k / base为符合要求的数字，然后base除以i，k对base取模，求下一个数字
	{
		std::string::iterator pos = next(S.begin(), k / base);
		result.push_back(*pos);
		S.erase(pos);
	}
	result.push_back(S[0]); // 最后一个  i等于0的话不能进行base除以i的操作
	return result;
}
std::string getPermutation(int n, int k)
{
	std::string s(n, '0');
	std::string result;
	for (int i = 0; i < n; ++i) //算出第一个序列，即123...n
		s[i] += i + 1;
	return kth_permutation(s, k);
}
