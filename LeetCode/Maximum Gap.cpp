#include<vector>
#include<algorithm>

//��Ŀ����������һ��δ��������飬�ҵ�����������Ԫ�������Ĳ�ֵ
//�ⷨ������Ͱ�����ȼ��������е�������СԪ�أ�Ȼ�����Ͱ�Ĵ�С�������Ͱ�ĸ�����Ҫ��1������¼ÿ��Ͱ��������СԪ�أ����н��һ��������ÿ��Ͱ��
//��СԪ�غ���һ��Ͱ�����Ԫ�صĲ�֮��

int maximumGap(std::vector<int>& nums)
{
	if (nums.size() < 2)
		return 0;
	// 1. ����õ�Ͱ����ȡƽ��������������ֵ����Сֵ֮����Լ�����õ�Ͱ��
	// ��Ϊ��������ֵ����ƽ���ֲ���ʱ�����ȡͰ���ɵ�ʱ�临�Ӷ���0(n)
	int maxVal = *max_element(nums.begin(), nums.end());
	int minVal = *min_element(nums.begin(), nums.end());
	int agGap = ceil((double) (maxVal - minVal) / (nums.size() - 1)); // ƽ�����  ceilΪ��ȡ���������õ���С�ڸ���ֵ����С������floor����ȡ���������õ�����������ֵ���������
	int bucketCount = (maxVal - minVal) / agGap + 1;  //ע���������Ͱ�ĸ���
	// 2. ��¼ÿ��Ͱ�����ֵ����Сֵ
	std::vector<std::pair<int, int> > buckets(bucketCount, std::make_pair(INT_MIN, INT_MAX)); // ��ʼ��Ͱ
	for (int val : nums)
	{
		int bucketNum = (val - minVal) / agGap;
		if (val > buckets[bucketNum].first)
			buckets[bucketNum].first = val; // �洢���ֵ
		if (val < buckets[bucketNum].second)
			buckets[bucketNum].second = val; // �洢��Сֵ
	}
	// 3. ��������
	int maxGap = 0, lastMax = minVal;
	for (std::pair<int, int> bucket : buckets)
	{
		if (bucket.first == INT_MIN)
			continue; // ��Ͱ
		int curMax = bucket.first, curMin = bucket.second;
		maxGap = std::max(maxGap, curMin - lastMax);
		lastMax = curMax;
	}
	return maxGap;
}