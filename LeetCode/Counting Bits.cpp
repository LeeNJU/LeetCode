#include<vector>
//��Ŀ����:����һ������n,���ش�0��n֮���������Ķ����Ʊ�ʾ�а�����1�ĸ���������n = 5, ����[0,1,1,2,1,2]
//�ⷨ����:����i��1����������i & (i - 1)��1�ĸ�����1������i = 0110��i - 1 = 0101��i & (i - 1) = 0100,
//        ��Ϊi & (i - 1)��i�����ұߵ�1�����0������Ҫ��1.

std::vector<int> countBits(int num) 
{
	std::vector<int> result(num + 1, 0);
	for (int i = 1; i <= num; ++i)
		result[i] = result[i & (i - 1)] + 1;
	return result;
}