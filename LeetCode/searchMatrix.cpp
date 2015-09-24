#include<vector>
//题目描述:给定一个二维数组，每一行已经排好序，且下一行的元素都比上一行的元素大，从这个数组中找到给定的值target，返回
//        true或false
//解法描述:二分法，把二维数组看成一维数组，用二分法查找，middle要换算成二维数组中的坐标

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

//version2
//题目描述:给定一个二维数组，每一行已排好序，每一列也已经排好序，但是不保证下一行的元素比上一行大，在这个矩阵中查找
//解法描述:从右上角开始查找，如果比target小，那么col向下移动一位，如果比target大,那么row向左移动一位

bool searchMatrix2(std::vector<std::vector<int>>& matrix, int target) 
{
	if (matrix.empty())
		return false;

	int row = 0, col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0)
	{
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col] < target)
			++row;
		else
			--col;
	}
	return false;
}