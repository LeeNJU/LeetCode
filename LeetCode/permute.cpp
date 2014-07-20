#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

void permutation(vector<vector<int> >& vec, const vector<int>& num, vector<int>& item, int depth)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		vector<int>::iterator iter = item.end();
		if (find(item.begin(), iter - depth, num[i]) == iter - depth)
		{
			item[num.size() - depth] = num[i];
			if (depth == 1)
			{
				vec.push_back(item);
			}
			else
			{
				permutation(vec, num, item, depth - 1);
			}
		}
	}
}

vector<vector<int> > permute(vector<int>& num)
{
	vector<vector<int> > result;
	vector<int> item(num.size());
	permutation(result, num, item, num.size());
	return result;
}
