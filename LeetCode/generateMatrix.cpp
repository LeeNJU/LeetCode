#include<vector>

//����һ������n����������ʽת����һ��n*n�Ķ�ά���飬����n=3��ת����array={{1,2,3}��{8,9,4}��{7,6,5}}
//�ⷨ�����ĸ�forѭ���ֱ�����������У�����Ҫ�������½Ǻ����½���ȵ��������array={{1,2,3}}

std::vector<std::vector<int> > generateMatrix(int n)
{
	std::vector<int> temp(n, 0);
	std::vector<std::vector<int>> result(n, temp);

	int leftCorner = 0, rightCorner = n - 1;//�����������Σ��������½Ǻ����½�ֻ��Ҫһ��������¼
	for (int i = 1; i <= n * n;)
	{
		for (int j = leftCorner; j <= rightCorner; ++j)//�������һ��
			result[leftCorner][j] = i++;
		for (int j = leftCorner + 1; j <= rightCorner; ++j)//����ұ�һ��
			result[j][rightCorner] = i++;
		for (int j = rightCorner - 1; j >= leftCorner; --j)//�������һ��
			result[rightCorner][j] = i++;
		for (int j = rightCorner - 1; j > leftCorner; --j)//������һ��
			result[j][leftCorner] = i++;

		++leftCorner;
		--rightCorner;
	}

	return result;
}
