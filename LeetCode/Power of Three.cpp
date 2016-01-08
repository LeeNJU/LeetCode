//题目描述:给定一个数n，判断n是不是3的幂
//解法描述:不断除以3，直到等于1或者不能被3整除

bool isPowerOfThree(int n) 
{
	if (n <= 0)
		return false;

	while (n != 1)
	{
		if (n % 3 != 0)
			return false;
		n /= 3;
	}
	return true;
}