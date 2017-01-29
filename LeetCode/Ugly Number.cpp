#include<vector>
#include<algorithm>
//��Ŀ������ugly number��ָֻ�ܱ�2��3��5�����������ж�һ�����ǲ���ugly number��1��ugly number
//�ⷨ��������ͣ����2��3��5ȥ����������ֳ���2��3��5��Լ�����Ͳ���ugly number
bool isUgly(int num) 
{
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

//����2:�����n��ugly number
//�ⷨ����:�ҳ�����ugly number�Ĺ��ɣ�һ��ugly number������һ����С��ugly number����2��3��5�õ���index2��
//         index3��index5������ʾǰһ����С��ugly number
int nthUglyNumber(int n) 
{
	std::vector<int> result(n, 0);
	int index2 = 0, index3 = 0, index5 = 0;
	result[0] = 1;
	for (int i = 1; i < n; i++)
	{
		result[i] = std::min(std::min(result[index2] * 2, result[index3] * 3), result[index5] * 5);
		if (result[i] == result[index2] * 2) //ע�����������if else����Ϊ��ǰ��С��ugly number����
			++index2;                        //����2��3����5ͬʱ�õ�
		if (result[i] == result[index3] * 3) 
			++index3;
		if (result[i] == result[index5] * 5) 
			++index5;
	}
	return result[n - 1];
}

//version 3:super ugly number
//��Ŀ����:����һ���������飬�ҵ���n������Щ����Ϊ������ugly number
//�ⷨ����:�ⷨ���ƣ�������������Ϊk����Ҫ�����鱣��ÿһ���������±�

int nthSuperUglyNumber(int n, std::vector<int>& primes)
{
	std::vector<int> index(primes.size(), 0);
	std::vector<int> result(n,1);

	for (int i = 1; i < n; ++i)
	{
		int num = INT_MAX;
		for (int j = 0; j < primes.size(); ++j)//�ҵ���Сֵ
			num = std::min(num, result[index[j]] * primes[j]);

		for (int j = 0; j < primes.size(); ++j)//���µõ���Сֵ���±�
		{
			if (result[index[j]] * primes[j] == num)
				++index[j];
		}
		result[i] = num;
	}
	return result[n - 1];
}