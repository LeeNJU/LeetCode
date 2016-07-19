#include<vector>
#include<unordered_map>
#include<algorithm>
#include<xfunctional>
#include<queue>
//��Ŀ����:����һ�����飬������ִ�������k����
//�ⷨ����:map��¼Ԫ�س��ִ�����Ȼ������С�ѱ���

std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
	std::unordered_map<int, int> count;
	for (int element : nums) 	
		++count[element];

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	for (auto &element : count) 
	{
		if (q.size() < k)
			q.push(std::make_pair(element.second, element.first));
		else 
		{
			if (q.top().first < element.second)
			{
				q.pop();
				q.push(std::make_pair(element.second, element.first));
			}
		}
	}

	std::vector<int> result(k, 0);
	while (!q.empty()) 
	{
		result[--k] = q.top().second;
		q.pop();
	}
	return result;
}