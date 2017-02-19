#include<vector>
#include<algorithm>
#include<set>
//��Ŀ����:�����������飬�ҳ���������֮��Ĺ���Ԫ�أ����صĽ���в������ظ�Ԫ�ء�
//�ⷨ����:��������Ȼ����˫ָ��

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0, j = 0;
	std::set<int> set;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			++i;
		else if (nums1[i] > nums2[j])
			++j;
		else
		{
			set.insert(nums1[i]);
			++i;
			++j;
		}
	}

	return std::vector<int>(set.begin(), set.end());
}

//version2:�����������ظ�Ԫ�أ���Ԫ�س����˼��Σ�Ӧ���ڽ���з�ӳ����
std::vector<int> intersection2(std::vector<int>& nums1, std::vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int i = 0, j = 0;
	std::vector<int> result;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			++i;
		else if (nums1[i] > nums2[j])
			++j;
		else
		{
			result.push_back(nums1[i]);
			++i;
			++j;
		}
	}
	return result;
}