//题目描述：给定一个数组和一个值，删除数组中和该值相等的元素并返回删除后的数组长度
//解法：index记录新的数组下标，i遍历数组，A[index]和A[i]表明该元素是不需要删除的元素，index++，如果相等，i++，index不变

int removeElement(int A [], int n, int elem)
{
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != elem)
		{
			A[index++] = A[i];
		}
	}
	return index;
}