#include<iostream>
#include<algorithm>
//给定一个数组，包含0,1,2，给数组进行排序，不能使用sort方法
//解法：用双指针，一个指针指向开头，[0,red - 1]表示全是0， 一个指针指向后面，[blue + 1, n - 1]表示全是2， 中间为1，循环整个数组，把2往后交换，把0往前交换，复杂度为O(n)
//注意：交换两个元素之后，不能进行++i，因为交换后的元素可能相同
void sortColors(int A[], int n)
{
	int red = 0, blue = n - 1;
	for (int i = 0; i < blue + 1;)//i的范围只需要到blue+1即可
	{
		if (A[i] == 2)
			std::swap(A[i], A[blue--]);
		else if (A[i] == 0)
			std::swap(A[i++], A[red++]);//！！！注意这里A[i++]
		else
			++i;
	}
}
