#include<vector>

//��Ŀ������һ��m*n�ľ������ĳһ��Ԫ�ص���0����ô�Ͱ���һ�к���һ�е�����Ԫ����Ϊ0
//�ⷨ�����Ӷ�m*n,�ռ临�Ӷ�O(1)��������ǣ�����Ϊ0. ��ɨ���һ�к͵�һ�飬�����Ԫ�ص���0��������ǣ����һ��Ԫ��a[i][j]����0����ô��a[0][j]��a[i][0]��Ϊ0��Ϊ��ǣ�
//Ȼ��ɨ�������������a[0][j]����a[i][0]����0���Ͱ�a[i][j]��Ϊ0

void setZeroes(std::vector<std::vector<int> > &matrix)
{
	const int row = matrix.size();
	const int col = matrix[0].size();
	bool row_has_zero = false;
	bool col_has_zero = false;

	for (int i = 0; i < col; ++i)//����һ���Ƿ����0
	{
		if (matrix[0][i] == 0)
		{
			row_has_zero = true;
			break;
		}
	}

	for (int i = 0; i < row; ++i)//����һ���Ƿ����0
	{
		if (matrix[i][0] == 0)
		{
			col_has_zero = true;
			break;
		}
	}

	for (int i = 1; i < row; ++i)//��ʼɨ��������ĳ��Ԫ�ص���0���ͰѶ�Ӧ�ĵ�һ���к͵�һ����Ϊ0��Ϊ���
	{
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if (row_has_zero)//�����һ�д���0���Ͱѵ�һ������Ԫ����Ϊ0
	for (int j = 0; j < col; ++j)
		matrix[0][j] = 0;

	if (col_has_zero)//�����һ�д���0���Ͱѵ�һ������Ԫ����Ϊ0
	for (int i = 0; i < row; ++i)
		matrix[i][0] = 0;
}