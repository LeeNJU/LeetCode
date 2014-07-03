#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

void permutation(vector<vector<int> >& vec, const vector<int>& num, deque<int>& item)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		if (find(item.begin(), item.end(), num[i]) == item.end())
		{
			item.push_back(num[i]);
			if (item.size() == num.size())
			{
				vec.push_back(vector<int>(item.begin(), item.end()));
				item.pop_back();
			}
			else
			{
				permutation(vec, num, item);
			}
		}
		item.clear();
	}
}

vector<vector<int> > permute(vector<int>& num)
{
	vector<vector<int> > result;
	deque<int> item;
	permutation(result, num, item);
	return result;
}

int main()
{
	vector<int> num;
	num.push_back(0);
	num.push_back(1);
	vector<vector<int> > vec = permute(num);
	return 0;
}