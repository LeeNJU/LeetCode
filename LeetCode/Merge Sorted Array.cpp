#include<vector>
#include<algorithm>
//��Ŀ����������������������A��B������ϲ�,��������A�������㹻�Ŀռ���������B
//�ⷨ��������A��B�Ľ�β��ʼɨ�裬���ν�ֵ�ϴ�ķŵ�����A������棬��������Bʣ�µ����ݿ���������A��

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int index = m + n - 1;
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])
			nums1[index--] = nums1[i--];
		else
			nums1[index--] = nums2[j--];
	}

	if (i < 0)
		copy(nums2.begin(), nums2.begin() + j + 1, nums1.begin());
}

