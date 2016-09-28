#include<vector>
#include<algorithm>
//题目描述:给定一个未排序的数组，判断是否存在一个长度为3递增的子序列，例如
//         num[i] < num[j] < num[k]并且i < j < k
//解法描述:遍历数组，保存第一个最小值和倒数第二小的值，如果当前元素比最小值
//         和倒数第二小的值都小，说明此时有3个递增的子序列了，返回true
bool increasingTriplet(vector<int>& nums) 
{
	int m1 = INT_MAX, m2 = INT_MAX;
	for (auto a : nums) 
	{
		if (m1 >= a) 
			m1 = a;
		else if (m2 >= a) 
			m2 = a;
		else 
			return true;
	}
	return false;
}