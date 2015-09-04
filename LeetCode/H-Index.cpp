#include<vector>
#include<algorithm>
//题目描述：给定一个数组表示科学家的论文引用数，求出总的引用指数h，使得h篇论文的引用指数大于等于h，剩下的N-h篇论文的
//         引用指数小于h
//解法描述：先排序，用index表示指数，从后向前扫描
int hIndex(std::vector<int>& citations) 
{
	sort(citations.begin(), citations.end());
	int index = 1;
	for (; index <= citations.size(); ++index)
	{
		if (citations[citations.size() - index] < index)
			break;
	}
	return index - 1;
}

//变种：如果数组已经被排好序了，如何求这个index，要求运行时间是log(n)
//解法描述：用二分法进行查找
int hIndex2(std::vector<int>& citations) 
{
	if (citations.empty())
		return 0;

	int left = 0, right = citations.size() - 1, middle = 0;
	int result = 0;//保存结果
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (citations[middle] >= (citations.size() - middle))//注意之类的下标是citations.size() - middle
		{
			result = citations.size() - middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return result;
}