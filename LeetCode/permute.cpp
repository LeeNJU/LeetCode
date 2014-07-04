#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

void permutation(vector<vector<int> >& vec, const vector<int>& num, vector<int>& item, int depth)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		/*
		bool existed = false;
		for (size_t j = 0; j < item.size() - depth; ++j)
		{
			if (item[j] == num[i])
			{
				existed = true;
				break;
			}
		}*/
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

int main()
{
	vector<int> num;
	num.push_back(0);
	num.push_back(1);
	vector<vector<int> > vec = permute(num);
	cout << vec.size() << endl;
	cout << vec[0][0] << " " << vec[0][1] << endl;
	cout << vec[1][0] << " " << vec[0][1] << endl;
	return 0;
}