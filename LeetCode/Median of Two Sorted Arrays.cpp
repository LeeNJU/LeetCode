#include<algorithm>
#include<vector>

//题目描述:给定两个已序数组，找到这两个数组的中位数，要求时间复杂度为O(log(m+n))
//解法描述:转换为找到第K小的元素问题，k为两个数组的中位数，用两个指针分别指向两个数组的第k/2个元素(要判断
//        数组是否有这么长)

double find_kth(std::vector<int>& A, int m, std::vector<int>& B, int n, int k)
{
	if (A.size() > B.size())//默认A数组要小
		return find_kth(B, n, A, m, k);
	if (m >= A.size())//A数组为空，说明第K小的元素在数组B中
		return B[n + k - 1];
	if (n >= B.size())
		return A[m + k - 1];

	if (k == 1)//找第1小的元素
		return std::min(A[m], B[n]);

	int pa = std::min(k / 2, int(A.size() - m)), pb = k - pa;//注意pb的算法，k-pa可以使pa和pb加起来等于k
	if (A[m + pa - 1] < B[n + pb - 1])//如果小于，表示数组A的pa-1位置以下的元素都不是，可以删除
		return find_kth(A, m + pa, B, n, k - pa);
	else if (A[m + pa - 1] > B[n + pb - 1])//如果大于，表示数组B的pb - 1下标以下的元素都不是第k小的元素，可以删除
		return find_kth(A, m, B, n + pb, k - pb);
	else//相等，表示这就是第k小的元素，因为pa+pb等于k
		return A[m + pa - 1];
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	const int total = nums1.size() + nums2.size();
	if (total % 2)//奇数
		return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
	else//偶数
		return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
}