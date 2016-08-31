#include<cmath>
#include<algorithm>
//题目描述:给定一个数n，判断n是不是3的幂
//解法描述:不断除以3，直到等于1或者不能被3整除,还可以用数学方法，找到int类型中最大的3的幂，然后这个幂对n进行
//        取模，如果n是3的幂，取模的结果一定是0.

bool isPowerOfThree(int n) 
{
	if (n <= 0) 
		return false;
	int t = pow(3, (int) (log(INT_MAX) / log(3))); //t是最大的3的幂
	return (t % n == 0);
}