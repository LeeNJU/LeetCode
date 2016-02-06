#include<vector>
#include<algorithm>
//��Ŀ����:����һ������ÿһ��ÿһ�ж����ź������kС��Ԫ��
//�ⷨ����:��ÿһ�б���һ����index��ÿ���ҵ���С��Ԫ�أ�Ȼ����index�����ƶ�������Ҳ�����ö�
int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
{
	if (matrix.empty())
		return 0;

	int col = matrix[0].size();
	std::vector<int> index(col, 0); //ÿһ�б���һ����index

	int result = 0;
	for (int i = 0; i < k; ++i)
	{
		int min_index = 0;
		int min_val = INT_MAX;
		for (int j = 0; j < index.size(); ++j)
		{
			if (index[j] == -1) //��һ�е�Ԫ���Ѿ���������
				continue;

			if (matrix[index[j]][j] < min_val) //�ҵ���СԪ������һ��
			{
				min_val = matrix[index[j]][j];
				min_index = j;
			}
		}

		result = matrix[index[min_index]][min_index];
		++index[min_index];  //����СԪ�ص���index�����ƶ�(��1)
		if (index[min_index] >= matrix.size()) //�ж���index�Ƿ���Ч
			index[min_index] = -1;
	}
	return result;
}