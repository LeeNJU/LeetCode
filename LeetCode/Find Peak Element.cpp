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


//题目描述:给定一个二维数组，数组的第二行的元素比第一行的大，倒数第二行的元素比倒数第一行的元素大，第二列的元
//        素比第一列的元素大，倒数第二列的元素比倒数第一列的元素大，现在要找到一个元素，使得这个元素比上下
//        左右4个元素都大,例如
//        [
//      	[1, 2, 3, 6, 5],
//      	[16, 41, 23, 22, 6],
//      	[15, 17, 24, 21, 7],
//      	[14, 18, 19, 20, 10],
//      	[13, 14, 11, 10, 9]
//        ]
//解法描述:对行进行二分查找，找到middle行的最大元素，然后与相邻的上下两个元素进行比较，如果上面的元素大，则
//        在上半部分必然存在一个peak元素，例如假设A[middle][x]是A[middle]行的最大元素，并且A[middle][x - 1]
//        比A[middle][x]大，那么可以在A[middle]行找最大的元素A[middle][y]，使得这个元素比A[middle][y + 1],
//        A[middle][y - 1]和A[middle + 1][y - 1]要大，由于我们保证第二行的元素比第一行的元素大，如果一直
//        移动middle行的话，一定可以找到peak元素，同理如果下面的元素大，那么在下半部分也必然存在一个peak元素

int findPeak(std::vector<int>& v) 
{
	int res = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > v[res])
			res = i;
	}
	
	return res;
}

std::vector<int> findPeakII(std::vector<std::vector<int>> A) 
{
	std::vector<int> res;
	int left = 0, right = A.size() - 1;
	while (left <= right) 
	{
		int mid = left + ((right - left) >> 1);
		int col = findPeak(A[mid]); //找到这一行的最大元素
		if (A[mid][col] < A[mid + 1][col]) 
			left = mid + 1;
		else if (A[mid][col] < A[mid - 1][col]) 
			right = mid - 1;
		else 
			return{ mid, col };
	}
	return res;
}