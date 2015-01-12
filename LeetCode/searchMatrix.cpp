#include<vector>
//����һ����ά���飬������������ҵ�������ֵtarget������true��false
//�ⷨ�����ַ����Ѷ�ά���鿴��һά���飬�ö��ַ����ң�middleҪ����ɶ�ά�����е�����

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