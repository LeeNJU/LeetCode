#include<vector>
//给定一个二维数组，从这个数组中找到给定的值target，返回true或false
//解法：二分法，把二维数组看成一维数组，用二分法查找，middle要换算成二维数组中的坐标

bool searchMatrix(std::vector<std::vector<int> > &matrix, int target)
{
	int row = matrix.size(), col = matrix[0].size();
	int first = 0, last = row * col - 1, value = 0, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		value = matrix[middle / col][middle % col];//换算成二维数组中的坐标，然后得到它的值进行二分查找
		if (value == target)
			return true;
		else if (value < target)
			first = middle + 1;
		else
			last = middle - 1;
	}
	return false;
}