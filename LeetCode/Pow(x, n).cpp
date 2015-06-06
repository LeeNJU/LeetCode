//题目描述：实现pow(x,n),即求x的n次方
//解法描述：递归，注意n可能为负

double power(double x, int n) 
{
	if (n == 0) 
		return 1;
	double v = power(x, n / 2);
	if (n % 2 == 0) //判断n是不是偶数
		return v * v;
	else 
		return v * v * x;
}

double myPow(double x, int n)
{
	if (n < 0) 
		return 1.0 / power(x, -n);
	else 
		return power(x, n);
}