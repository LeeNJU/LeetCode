#include<string>
#include<vector>

//��Ŀ����������һ��ֵn��k�����123..n�ĵ�k���׳�
//�ⷨ������ע����ѧ��ʽ�� a1��a2,a3,... an, a1 = k / (n - 1)!, k2 = k % (n - 1)!, ���ΰ�k / (n - 1)!��ֵ���뵽�����

int factorial(int n) // n�Ľ׳�
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
	--k; // ���б����0 ��ʼ
	for (int i = n - 1; i > 0; k %= base, base /= i, --i) // ��n - 1��ʼ��k / baseΪ����Ҫ������֣�Ȼ��base����i��k��baseȡģ������һ������
	{
		std::string::iterator pos = next(S.begin(), k / base);
		result.push_back(*pos);
		S.erase(pos);
	}
	result.push_back(S[0]); // ���һ��  i����0�Ļ����ܽ���base����i�Ĳ���
	return result;
}
std::string getPermutation(int n, int k)
{
	std::string s(n, '0');
	std::string result;
	for (int i = 0; i < n; ++i) //�����һ�����У���123...n
		s[i] += i + 1;
	return kth_permutation(s, k);
}
