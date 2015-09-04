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