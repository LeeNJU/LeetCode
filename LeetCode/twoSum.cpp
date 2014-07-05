#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;


vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> result(2, 0);

	multimap<int, int> m;
	for (size_t i = 0; i < numbers.size(); ++i)
		m.insert(pair<int, int>(numbers[i], i + 1));

	multimap<int, int>::iterator iter = m.begin();
	while (iter != m.end())
	{
		multimap<int, int>::iterator index = m.find(target - iter->first);
		if (index != m.end())
		{
			multimap<int, int>::iterator next = ++index;//防止找到同一个下标
			if (next != m.end() && (--index)->second != iter->second)
			{
				result[0] = iter->second;
				result[1] = index->second;
				break;
			}

		}
		++iter;
	}

	sort(result.begin(), result.end());
	return result;
}

