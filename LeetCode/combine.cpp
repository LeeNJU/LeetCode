#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	vector<int> vec(k, 0);
	for (int i = 1; i <= n - k + 1; ++i)
	{
		vec[0] = i;
		combinations(n, k, result, vec, i + 1, 1);
	}
	return result;
}

void combinations(int n, int k, vector<vector<int>>& result, vector<int> vec, int index, int depth)
{
	if (depth == k)
	{
		result.push_back(vec);
		return;
	}

	for (int i = index; i <= n; ++i)
	{
		vec[depth] = i;
		combinations(n, k, result, vec, i + 1, depth + 1);
	}
}
