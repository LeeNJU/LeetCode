//题目描述:给定一个值n，代表有n个灯泡，刚开始所有灯泡都是off，第i轮，每i个灯泡进行反转(off变on，on变off)，求最后有几个灯泡是on
//解法描述:第i个灯泡，会在i的因数轮被反转，因此只要找到某个数，它的因数的个数是奇数，那么最后就是on。所有的完全平方数的因数个数
//        是奇数，所以只要找到所有完全平方数就可以了
int bulbSwitch(int n) 
{
	int result = 0;
	int count = 1;
	while (count * count <= n)
	{
		++result;
		++count;
	}
	return result;
}