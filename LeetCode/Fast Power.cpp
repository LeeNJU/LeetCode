//��������:���ټ���a��n�η���b����ȡģ�Ľ��
//�ⷨ����:����ȡģ����Ĺ�ʽ��(a * b) % p = (a % p * b % p) % p
int fastPower(int a, int b, int n) 
{
	if (n == 0)
		return 1 % b;

	if (n == 1)
		return a % b;

	long num = fastPower(a, b, n / 2); //����Ҫע����������⣬������long
	num = num * num;

	num = num % b;
	if (n % 2 == 1)//����n����ż
		num = num * (a % b);

	return num % b;
}