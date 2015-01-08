#include<vector>
#include<algorithm>

void twoSumClosest(std::vector<int>& num, int index, int target)
{
	int first = index + 1, last = num.size() - 1;
	int sum = num[index] + num[first] + num[last];
	bool isBig = sum > target ? true : false;
	while (first < last)
	{
		if (isBig && abs(sum - target) > abs(num[index] + num[first] + num[last] - target))
		{
			sum = num[index] + num[first] + num[last];
			--last;
		}
		else if (isBig && abs(sum - target) <= abs(num[index] + num[first] + num[last] - target))
		{
			--last;
		}
		else if (!isBig && abs(sum - target) > abs(num[index] + num[first] + num[last] - target))
		{

		}
	}
}

int threeSumClosest(std::vector<int> &num, int target) {
	sort(num.begin(), num.end());
	for (int i = 0; i < (int) num.size() - 2; ++i)
	{
		if (i != 0 && num[i] == num[i - 1])
			continue;

	}
	return 0;
}