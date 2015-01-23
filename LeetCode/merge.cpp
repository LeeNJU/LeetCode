//题目描述：给定两个已序数组，把他们合并
//解法：分别逆序遍历两个数组，依次把最大的放到后面，注意遍历结束后还要判断是否有剩余的元素

void merge(int A [], int m, int B [], int n)
{
	int ia = m - 1, ib = n - 1, i = m + n - 1;
	while (ia >= 0 && ib >= 0)
		A[i--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];

	while (ib >= 0)
		A[i--] = B[ib--];
}