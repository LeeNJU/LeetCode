#include<vector>
//��Ŀ����:����һ����ά���飬ÿһ���Ѿ��ź�������һ�е�Ԫ�ض�����һ�е�Ԫ�ش󣬴�����������ҵ�������ֵtarget������
//        true��false
//�ⷨ����:���ַ����Ѷ�ά���鿴��һά���飬�ö��ַ����ң�middleҪ����ɶ�ά�����е�����

bool searchMatrix(std::vector<std::vector<int> > &matrix, int target)
{
	int row = matrix.size(), col = matrix[0].size();
	int first = 0, last = row * col - 1, value = 0, middle = 0;
	while (first <= last)
	{
		middle = (first + last) / 2;
		value = matrix[middle / col][middle % col];//����ɶ�ά�����е����꣬Ȼ��õ�����ֵ���ж��ֲ���
		if (value == target)
			return true;
		else if (value < target)
			first = middle + 1;
		else
			last = middle - 1;
	}
	return false;
}

//version2
//��Ŀ����:����һ����ά���飬ÿһ�����ź���ÿһ��Ҳ�Ѿ��ź��򣬵��ǲ���֤��һ�е�Ԫ�ر���һ�д�����������в���
//�ⷨ����:�����Ͻǿ�ʼ���ң������targetС����ôcol�����ƶ�һλ�������target��,��ôrow�����ƶ�һλ

bool searchMatrix2(std::vector<std::vector<int>>& matrix, int target) 
{
	if (matrix.empty())
		return false;

	int row = 0, col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0)
	{
		if (matrix[row][col] == target)
			return true;
		else if (matrix[row][col] < target)
			++row;
		else
			--col;
	}
	return false;
}