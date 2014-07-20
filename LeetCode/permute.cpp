#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>


void permutation(std::vector<std::vector<int> >& vec, const std::vector<int>& num, std::vector<int>& item, int depth)
{
	for (size_t i = 0; i < num.size(); ++i)
	{
		std::vector<int>::iterator iter = item.end();
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

std::vector<std::vector<int> > permute(std::vector<int>& num)
{
	std::vector<std::vector<int> > result;
	std::vector<int> item(num.size());
	permutation(result, num, item, num.size());
	return result;
}
