#include<vector>
#include<algorithm>
//题目描述：给定两个已序数组A和B，将其合并,假设数组A后面有足够的空间容纳数组B
//解法描述：从A和B的结尾开始扫描，依次将值较大的放到数组A的最后面，最后把数组B剩下的内容拷贝到数组A中

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

