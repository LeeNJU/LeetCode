#include<iostream>
#include<algorithm>
//题目描述：给定两个已序数组A和B，将其合并,假设数组A后面有足够的空间容纳数组B
//解法描述：从A和B的结尾开始扫描，依次将值较大的放到数组A的最后面，最后把数组B剩下的内容拷贝到数组A中

void mergeSortedArray(int* a, int lenA, int* b, int lenB)
{
	if (a == nullptr || b == nullptr)
		return;

	int indexA = lenA - 1, indexB = lenB - 1, cur = lenA + lenB - 1;

	while (indexA >= 0 && indexB >= 0)
	{
		a[cur--] = a[indexA] <= b[indexB] ? b[indexB--] : a[indexA--];//依次将值较大的放到数组A的后面
	}

	std::copy(b, b + indexB + 1, a);//把B剩下的复制到A前面
}

