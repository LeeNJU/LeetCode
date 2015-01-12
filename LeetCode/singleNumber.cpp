//给定一个数组，数组中的元素都会出现2次，只有其中一个元素只出现1次，找出这个元素
//解法：对每个元素进行异或操作，因为出现2次的元素进行异或之后每一位等于0，再与剩下的元素进行异或，结果不变，最终结果就是它


int singleNumber(int A[], int n)
{
	int result = A[0];
	for (int i = 1; i < n; ++i)
		result ^= A[i];//注意异或操作的符号
	return result;
}
