#include<vector>

//��Ŀ����������һ��ֵn�����nλ��gray code����������gray code�ڶ����Ʊ�ʾ��ֻ��һλ���в������n = 2��gray codeΪ00�� 01�� 11��10
//�ⷨ�������ҹ��ɼ��ɣ�nΪ��gray code����������ɣ�һ������n-1λ�����룬�ټ��� 1<<(n-1)��n-1λ�����������ĺ�

std::vector<int> grayCode(int n)
{
	std::vector<int> result;
	result.push_back(0);
	for (int i = 0; i < n; i++) 
	{
		const int highest_bit = 1 << i;
		for (int j = result.size() - 1; j >= 0; j--) // Ҫ���ű��������ܶԳ�
			result.push_back(highest_bit | result[j]);
	}
	return result;
}