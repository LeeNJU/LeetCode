#include <vector>

//��Ŀ����:����һ�����飬������֮ǰ���ź��򣬵�����ĳһ���㱻������λ�ã�����4 5 6 7 0 1 2���ҵ����е���С
//        Ԫ�أ����������в������ظ�Ԫ��
//�ⷨ����:���ֲ���

int findMin(std::vector<int>& nums)//���м��Ԫ�������ұߵ�Ԫ�رȽϣ��ö��ַ���С��Χ�����Ӷ�ΪO(lgn)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (nums[middle] < nums[right])
			right = middle;
		else
			left = middle + 1;
	}
	return nums[left];
}

//�汾�������������а����ظ�Ԫ��
int findMin2(std::vector<int>& nums)
{
	int left = 0, right = nums.size() - 1, middle = 0;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (nums[left] == nums[right])//��������Ԫ����ȣ�ֻ��Ҫ�ƶ�left��rightһ��ָ��Ϳ����ˣ������������ƶ�,����[1,2,1]
			++left;
		else if (nums[middle] > nums[right])
			left = middle + 1;
		else
			right = middle;
	}
	return nums[left];
}