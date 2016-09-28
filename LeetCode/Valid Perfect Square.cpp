//题目描述:给定一个正整数，判断其是不是一个平方数，例如给定16，返回true
//解法描述:二分查找，注意溢出

bool isPerfectSquare(int num) 
{
	if (num <= 0)
		return false;

	long left = 1, right = num, middle = (left + right) / 2;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (middle * middle == num)
			return true;
		else if (middle * middle < num)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return false;
}