#include<vector>
//��Ŀ����:����һ����ά���飬ÿ��ÿ�ж��Ѿ��ź���Ҫ���k����С��Ԫ��
//�ⷨ����:��һ�����鱣�浱ǰÿһ����СԪ�ص��±꣬�������һά���飬�ҵ���С��Ԫ�أ�Ȼ���±��1�������ö���
//        �Ż�������СԪ�ص�ʱ�䡣

int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
{
	std::vector<int> index(matrix.size(), 0);
	int result = INT_MAX;

	for (int i = 0; i < k; ++i)
	{
		int minimum = INT_MAX;
		int position = 0;
		for (int j = 0; j < index.size(); ++j)
		{
			if (index[j] < matrix.size() && matrix[index[j]][j] < minimum)//��¼��СԪ���Լ��±�
			{
				minimum = matrix[index[j]][j];
				position = j;
			}
		}
		result = minimum;
		++index[position];
	}
	return result;
}