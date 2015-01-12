#include<vector>
//����һ�����������һ��ֵ�������ҳ����ֵ������ķ�Χ�����±��ʾ�������ֵ�����ڣ��򷵻�2��-1
//�ⷨ�����ַ�����lower_bound��upper_bound
std::vector<int> searchRange(int A [], int n, int target)
{
	std::vector<int> result;
	int left = 0, right = n - 1, middle = 0;
	int first = 0, last = n - 1;
	while (left <= right)//lower_boundԴ�룬Ѱ������ߵı߽�
	{
		middle = (left + right) / 2;
		if (A[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	first = left;
	if (first >= n || A[first] != target)//�ж�Ԫ���Ƿ������������
	{
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

	left = 0, right = n - 1, middle = 0;
	while (left <= right)//upper_boundԴ�룬Ѱ�����ұߵı߽�
	{
		middle = (left + right) / 2;
		if (A[middle] <= target)//�˴���Ψһ��ͬ�ĵط�
			left = middle + 1;
		else
			right = middle - 1;

	}
	last = left;

	result.push_back(first);
	result.push_back(last - 1);//upper_bound���ص���Ԫ�ص���һ��λ�ã�����Ҫ��ȥ1
	return result;
}