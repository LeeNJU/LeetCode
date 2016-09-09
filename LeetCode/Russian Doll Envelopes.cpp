#include<vector>
#include<algorithm>
//��Ŀ����:����һ��pair����ʾ�߶ȺͿ�ȣ����һ��pair�ĸ߶ȺͿ�ȶ�����һ��pair�Ĵ���ô���԰���һ��pair��
//        �����pair�������ܷŶ��ٸ�
//�ⷨ����:�������ٶ�̬�滮�����Ӷ�Ϊnƽ��������ͨ�����ֲ����Ż���nlogn��

bool compare(const std::pair<int, int>&x , const std::pair<int, int>& y) 
{ //ע�����������ʽ
	return x.first != y.first ? x.first < y.first : x.second > y.second;
}

int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) 
{
	if (envelopes.empty())
		return 0;

	sort(envelopes.begin(), envelopes.end(), compare);

	std::vector<int> dp(envelopes.size()), height(envelopes.size() + 1, INT_MAX);
	for (int i = 0; i < envelopes.size(); ++i) 
	{
		int k = lower_bound(height.begin(), height.end(), envelopes[i].second) - height.begin();
		dp[i] = k;
		height[k] = envelopes[i].second;
	}

	int result = 0;
	for (int i = 0; i < envelopes.size(); ++i) 
		result = std::max(result, dp[i]);

	return result + 1;
}