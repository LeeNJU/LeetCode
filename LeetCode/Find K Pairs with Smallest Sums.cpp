#include<vector>
#include<algorithm>
//��Ŀ����:���������������飬Ҫ���ҵ�����С��k����ϣ�����[1,1,2],[1,2,3],k = 10,����
//        [[1,1],[1,1],[2,1],[1,2],[1,2],[2,2],[1,3],[1,3],[2,3]]
//�ⷨ����:�������п�����ϣ������ѱ���k����С����ϡ�����ʹ��˫ָ���������©����������

//�ȽϺ���
bool compare(const std::pair<int, int> pair_one, const std::pair<int, int> pair_two)
{
	return pair_one.first + pair_one.second <= pair_two.first + pair_two.second;
}

std::vector<std::pair<int, int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
{
	std::vector<std::pair<int, int>> result;//���Ľ����Ҳ������Ϊ����
	for (int i = 0; i < std::min((int) nums1.size(), k); ++i)//�������
	{
		for (int j = 0; j < std::min((int) nums2.size(), k); ++j)
		{
			if (result.size() < k)//�ѵĴ�С����k��
			{
				result.push_back(std::pair<int, int>(nums1[i], nums2[j]));
				push_heap(result.begin(), result.end(), compare);
			}
			else if (nums1[i] + nums2[j] < result[0].first + result[0].second)//��ǰ��ϱȶѶ����С
			{
				result.push_back(std::pair<int, int>(nums1[i], nums2[j]));
				push_heap(result.begin(), result.end(), compare);
				pop_heap(result.begin(), result.end(), compare);
				result.pop_back();
			}
		}
	}
	return result;
}