#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬Ҫ���ҵ�һ�����䣬ʹ���������ĺ͵ľ���ֵ��ӽ�0
//�ⷨ����:f[i]��ʾ�����0��i�ĺͣ���ô���Ž��Ȼ��ĳ����f[i]��f[j]�Ĳ����pair��first�����0��i�ĺͣ�
//        second�����±꣬��pair�����������Ž��Ȼ�������������ڵ�����
std::vector<int> subarraySumClosest(std::vector<int> nums)
{
	std::vector<int> vec(2, 0);
	std::vector<std::pair<int, int>> f(nums.size(), std::make_pair(0, 0));
	f[0].first = nums[0];
	f[0].second = 0;

	for (int i = 1; i < nums.size(); ++i) //first�����0��i�ĺͣ�second�����±�
	{
		f[i].first = f[i - 1].first + nums[i];
		f[i].second = i;
	}

	sort(f.begin(), f.end());//����

	int diff = f[0].first;
	for (int i = 1; i < f.size(); ++i)
	{
		if (abs(f[i].first - f[i - 1].first) < abs(diff))
		{
			diff = f[i].first - f[i - 1].first;
			vec[0] = std::min(f[i - 1].second, f[i].second) + 1; //ע���������֮���±겻һ�����մ�С˳��
			vec[1] = std::max(f[i].second, f[i - 1].second);
		}
	}
	return vec;
}