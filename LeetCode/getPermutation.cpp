#include<string>
#include<vector>



std::string getPermutation(int n, int k)
{
	std::string result;

	int count = 1;
	for (int i = 1; i <= n; ++i)
		count *= i;

	for (int i = 0; i < n; ++i)
	{
		count = count / (n - i);
		result += (k / count + 1 + '0');
		k = k % count;
	}
	return result;
}
