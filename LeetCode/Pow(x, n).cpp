//��Ŀ������ʵ��pow(x,n),����x��n�η�
//�ⷨ�������ݹ飬ע��n����Ϊ��

double power(double x, int n) 
{
	if (n == 0) 
		return 1;
	double v = power(x, n / 2);
	if (n % 2 == 0) //�ж�n�ǲ���ż��
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