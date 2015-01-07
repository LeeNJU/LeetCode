#include<vector>
#include<string>
#include<algorithm>
using namespace std;


string getPermutation(int n, int k)//bugs
{
	string result(n, ' ');
	int count = 0;
	bool isDone = false;
	for (int i = 1; i <= n && !isDone; ++i)
	{
		result[0] = i + 48;
		permutation(result, n, 1, k, count, isDone);
	}
	return result;
}

void permutation(string& result, int n, int depth, int k, int& count, bool& isDone)
{
	if (depth == n)
	{
		++count;
		if (count == k)
		{
			isDone = true;
		}
		return;
	}

	for (int i = 1; i <= n && !isDone; ++i)
	{
		if (find(result.begin(), result.begin() + depth, i + 48) == (result.begin() + depth))
		{
			result[depth] = i + 48;
			permutation(result, n, depth + 1, k, count, isDone);
		}
	}
}