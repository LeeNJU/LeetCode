#include<vector>
#include<algorithm>
//题目描述：给定一个数组表示科学家的论文引用数，求出总的引用指数h，使得h篇论文的引用指数大于等于h，剩下的N-h篇论文的
//         引用指数小于h
//解法描述：不用排序，用index表示指数，从后向前扫描
int hIndex(std::vector<int>& citations) 
{
	int n = citations.size();

	std::vector<int> vec(n + 1, 0);//vec[i]表示引用为i的论文数
	for (int i = 0; i < n; i++) 
	{
		if (citations[i] > n) //vec[n]表示引用数大于等于n的论文数
			vec[n] += 1;
		else 
			vec[citations[i]] += 1;
	}

	int t = 0;
	for (int i = n; i >= 0; --i)//从后向前扫描
	{
		t += vec[i];
		if (t >= i) 
			return i;
	}
	return 0;
}

//变种：如果数组已经被排好序了，如何求这个index，要求运行时间是log(n)
//解法描述：用二分法进行查找
int hIndex2(std::vector<int>& citations) 
{
	if (citations.empty())
		return 0;

	int left = 0, right = citations.size() - 1, middle = 0;
	while (left <= right)//二分法查找下标，当left和right相等时，还要继续比较citations[left]
	{
		middle = (left + right) / 2;
		if (citations[middle] >= (citations.size() - middle))//注意之类的下标是citations.size() - middle
			right = middle - 1;
		else
			left = middle + 1;
	}
	return citations.size() - left;
}