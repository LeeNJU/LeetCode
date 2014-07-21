#include<vector>
#include<algorithm>
#include <iostream>

void twoSum(std::vector<std::vector<int>>& result, const std::vector<int>& num, int index, int target)
{
	std::vector<int> vec;
	int first = index + 1, last = num.size() - 1;//firstΪindex+1��Ϊ�˷�ֹͬһ������е������ظ�����
	while (first < last)
	{
		if (num[first] + num[last] > target)
			--last;
		else if (num[first] + num[last] < target)
			++first;
		else
		{
			vec.push_back(num[index]);
			vec.push_back(num[first]);
			vec.push_back(num[last]);
			std::cout << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
			result.push_back(vec);
			vec.clear();
			++first;
			--last;
			while (first < last && num[first] == num[first - 1])
				++first;
			while (first < last && num[last] == num[last + 1])
				--last;
		}
	}
}

std::vector<std::vector<int>> threeSum(std::vector<int>& num)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	for (size_t i = 0; i < num.size() - 3; ++i)
	{
		if (i != 0 && num[i] == num[i - 1])//��ֹ�ظ�������
			continue;
		twoSum(result, num, i, -num[i]);
	}
	return result;
}
