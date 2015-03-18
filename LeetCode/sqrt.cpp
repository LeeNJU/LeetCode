//题目描述：给定一个值x，求出它的平方根
//解法描述：二分查找，从1到x/2的范围，注意要记录上一个middle的值，因为下一个middle的值可能不符要求，上一个middle的值才是正解

int sqrt(int x) 
{
	int left = 1, right = x / 2;//范围是1到x/2
	int middle = (left + right) / 2;
	int last_mid = middle; // 记录最近一次mid
	
	if (x < 2) 
		return x;
	
	while (left <= right) 
	{
		middle = (right + left) / 2;
		if (x / middle > middle) // 不要用x > mid * mid，会溢出
		{
			left = middle + 1;
			last_mid = middle;
		}
		else if (x / middle < middle) 
		{
			right = middle - 1;
		}
		else 
		{
			return middle;
		}
	}
	return last_mid;
}