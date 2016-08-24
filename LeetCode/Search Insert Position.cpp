#include<vector>
//����һ�������һ��target�����������ҵ�target���������±꣬��������в�����target���򷵻ؿ��Բ����Ԫ�ص�λ�õ��±�
//�ⷨ�����ַ����ҽ���������ҵ���Ԫ����ɹ����أ����û���ҵ���Ԫ�أ�firstָ��ò����λ��
//�ö��ַ�������firstָ�����target����Сindex��lastָ��С��target�����index������array={1,3,5,6}����2�����ֽ�����firstָ��3��lastָ��1
int searchInsert(std::vector<int> nums, int n, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (nums[middle] == target)
			return middle;
		else if (nums[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return left;
}
