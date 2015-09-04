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

//����2�������n��ugly number
//�ⷨ�������ҳ�����ugly number�Ĺ��ɣ�һ��ugly number������һ����С��ugly number����2��3��5�õ���index2��index3��
//         index5������ʾǰһ����С��ugly number
int nthUglyNumber(int n) 
{
	std::vector<int> result(n, 0);
	int index2 = 0, index3 = 0, index5 = 0;
	result[0] = 1;
	for (int i = 1; i < n; i++)
	{
		result[i] = std::min(std::min(result[index2] * 2, result[index3] * 3), result[index5] * 5);
		if (result[i] == result[index2] * 2) 
			index2++;
		if (result[i] == result[index3] * 3) 
			index3++;
		if (result[i] == result[index5] * 5) 
			index5++;
	}
	return result[n - 1];
}