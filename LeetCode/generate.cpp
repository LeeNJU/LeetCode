#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > result;
	vector<int> vec;
	for (int i = 0; i < numRows; ++i)
	{
		vec.resize(i + 1);
		vec[0] = 1;
		vec[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			vec[j] = result[i - 1][j] + result[i - 1][j - 1];
		}
		result.push_back(vec);
		vec.clear();
	}
	return result;
}

