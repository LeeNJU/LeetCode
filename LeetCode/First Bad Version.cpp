//��Ŀ������isBadVersion��ϵͳ�ṩ��api���ܹ��ж�n�Ƿ���bad version������һ����n���ҵ���һ��bad version�����n��
//         bad version,��ôn֮���Ԫ�ض���bad version����Ϊ�����ǻ���ǰ��Ļ���
//�ⷨ���������ֲ���

bool isBadVersion(int n);

int firstBadVersion(int n) 
{
	int first = 1, last = n, middle = 1;
	while (first <= last)
	{
		middle = first + (last - first) / 2;//ע�����middle = (first + last) / 2��д�����ܻᵼ��firsr + last���
		if (isBadVersion(middle))
			last = middle - 1;
		else
			first = middle + 1;
	}
	return first;
}