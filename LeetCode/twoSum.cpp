#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

vector<int> twoSums(vector<int>& numbers, int target)
{
	vector<int> number(numbers.begin(), numbers.end());
	sort(number.begin(), number.end());
	vector<int> result;
	int first = 0, last = number.size() - 1;
	while (first < last)
	{
		if (number[first] + number[last] < target)
			++first;
		else if (number[first] + number[last] > target)
			--last;
		else
		{
			break;
		}
	}
	vector<int>::iterator iter = find(numbers.begin(), numbers.end(), number[first]);
	result.push_back(iter - numbers.begin() + 1);
	vector<int>::iterator iters = find(numbers.begin(), numbers.end(), number[last]);
	if (iter == iters)//防止找到同一个下标  例如0,0,3,2 始终会找到第一个元素0
	{
		iters = find(++iters, numbers.end(), number[last]);
	}
	result.push_back(iters - numbers.begin() + 1);
	sort(result.begin(), result.end());
	return result;
}

