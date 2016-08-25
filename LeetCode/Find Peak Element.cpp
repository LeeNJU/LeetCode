#include <vector>
//题目描述：给定一个数组，其中相邻元素不等，找到一个peak element，使它比左右相邻的两个元素都大，假设n[0]和n[n]都等于负无穷
//解法描述：扫描一遍，找到第一个比前面元素小的元素，下标减1即是答案

int findPeakElement(const std::vector<int> &num) 
{
	for (int i = 1; i < num.size(); ++i)
	    if (num[i] < num[i - 1])
		   return i - 1;

	return num.size() - 1;
}