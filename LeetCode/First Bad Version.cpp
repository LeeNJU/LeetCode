//题目描述：isBadVersion是系统提供的api，能够判断n是否是bad version，给定一个数n，找到第一个bad version，如果n是
//         bad version,那么n之后的元素都是bad version，因为后面是基于前面的基础
//解法描述：二分查找

bool isBadVersion(int n);

int firstBadVersion(int n) 
{
	int first = 1, last = n, middle = 1;
	while (first < last)
	{
		middle = first + (last - first) / 2;//注意这里，middle = (first + last) / 2的写法可能会导致firsr + last溢出
		if (isBadVersion(middle))
			last = middle;
		else
			first = middle + 1;
	}
	return first;
}