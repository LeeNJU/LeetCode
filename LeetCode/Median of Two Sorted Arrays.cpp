#include<algorithm>
//题目描述:给定两个已序数组，找到这两个数组的中位数，要求时间复杂度为O(log(m+n))
//解法描述:转换为找到第K小的元素问题，k为两个数组的中位数，用两个指针分别指向两个数组的第k/2个元素(要判断
//        数组是否有这么长)

double find_kth(int A[], int m, int B[], int n, int k)
{
	if (m > n)//总是假设m小于n，如果大于，把数组A和B调换
		return find_kth(B, n, A, m, k);
	if (m == 0)//A数组为空，说明第K小的元素在数组B中
		return B[k - 1];
	if (k == 1)//找第1小的元素
		return std::min(A[0], B[0]);

	int pa = std::min(k / 2, m), pb = k - pa;//注意pb的算法，k-pa可以使pa和pb加起来等于k
	if (A[pa - 1] < B[pb - 1])//如果小于，表示数组A的pa-1位置以下的元素都不是，可以删除
		return find_kth(A + pa, m - pa, B, n, k - pa);
	else if (A[pa - 1] > B[pb - 1])//如果大于，表示数组B的pb - 1下标以下的元素都不是第k小的元素，可以删除
		return find_kth(A, m, B + pb, n - pb, k - pb);
	else//相等，表示这就是第k小的元素，因为pa+pb等于k
		return A[pa - 1];
}

double findMedianSortedArrays(int A [], int m, int B [], int n)
{
	const int total = m + n;
	if (total % 2)//奇数
		return find_kth(A, m, B, n, total / 2 + 1);
	else//偶数
		return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2;
}

