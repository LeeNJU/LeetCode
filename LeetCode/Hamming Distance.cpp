//题目描述:给定两个整数，求出他们的二进制表示中，有多少位是不同的，例如1和4，二进制表示为0001和0100，有两位
//        是不同的，返回2
//解法描述:依次比较每一位

int hammingDistance(int x, int y) 
{
	int count = 0;
	int k = 32;
	while (k > 0 && x != y)
	{
		--k;
		if ((x & 1) != (y & 1))
			++count;

		x = x >> 1;
		y = y >> 1;
	}
	return count;
}