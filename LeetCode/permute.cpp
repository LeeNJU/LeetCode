#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void permutation(vector<vector<int> >& vec, vector<int>& number, vector<int>& item)
{
	for (size_t i = 0; i < number.size(); ++i)
	{
		if (find(item.begin(), item.end(), number[i]) == item.end())
		{
			item.push_back(number[i]);
			if (item.size() == number.size())
			{
				vec.push_back(item);
			}
			else
			{
				permutation(vec, number, item);
			}
			item.clear();
		}
	}
}

vector<vector<int> > permute(vector<int>& num)
{
	vector<vector<int> > result;
	vector<int> item;
	permutation(result, num, item);
	return result;
}

int main()
{
	vector<int> num;
	num.push_back(0);
	num.push_back(1);
	cout << permute(num).size() << endl;
	return 0;
}