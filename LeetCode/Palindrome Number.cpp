//题目描述:给定一个数n，判断这个数是不是palindrome，例如121是palindrome
//解法描述:先算出数字的长度，以便算出最左边的数字，然后依次取最左边和最右边的数字进行比较

bool isPalindrome(int x)//先取得数字的长度，再一次去最左边和最右边的数字比较，然后取出最左边和最右边的数字
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;

	int length = 1;
	while (x / 10 >= length) //用x除以10的方式来比较，防止length的值越界，  注意x等于10，100等的情况
		length *= 10;

	while (length > 1)
	{
		int left = x / length;
		int right = x % 10;
		if (left != right)
			return false;
		x %= length;
		x /= 10;
		length /= 100;
	}
	return true;
}
