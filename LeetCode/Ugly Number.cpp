//题目描述：ugly number是指只能被2，3和5整除的数，判断一个数是不是ugly number，1是ugly number
//解法描述：不停的用2，3和5去除，如果发现除了2，3和5的约数，就不是ugly number
bool isUgly(int num) {
	if (num <= 0)
		return false;

	while (num > 1)
	{
		if (num % 2 == 0)
			num /= 2;
		if (num % 3 == 0)
			num /= 3;
		if (num % 5 == 0)
			num /= 5;
		if (num != 1 && num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
			return false;
	}
	return true;
}