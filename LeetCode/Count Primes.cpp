#include<vector>

//��Ŀ����������һ��ֵn�������1��n�������ĸ���
//�ⷨ������˼·��3����������ô3�����б���������������5����������ô5�����б�������������

int countPrimes(int n) 
{
	std::vector<bool> isPrime(n, true); //����һ�������飬��ʼ��Ϊtrue
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < n; i++) 
	{
		if (!isPrime[i]) 
			continue;
		for (int j = i * i; j < n; j += i) //��i*i��ʼ������i=5��ʱ��5*2,5*3,��Щ��ǰ���Ѿ�������ˣ�ֱ�Ӵ�i*i��ʼ
			isPrime[j] = false;
	}

	int count = 0;
	for (int i = 2; i < n; i++) 
	{
		if (isPrime[i]) 
			count++;
	}

	return count;
}