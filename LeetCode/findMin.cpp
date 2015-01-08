#include <vector>

//����������û���ظ���Ԫ��
int findMin(std::vector<int> &num)//���м��Ԫ�������ұߵ�Ԫ�رȽϣ��ö��ַ���С��Χ�����Ӷ�ΪO(lgn)
{
	int left = 0, right = num.size() - 1, middle = (left + right) / 2;
	while (left < right)
	{
		if (num[middle] > num[right])
		{
			left = middle + 1;
		}
		else
		{
			right = middle;
		}
		middle = (left + right) / 2;
	}
	return num[left];
}