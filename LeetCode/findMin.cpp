#include <vector>

//��Ŀ����������һ�����飬������֮ǰ���ź��򣬵�����ĳһ���㱻������λ�ã�����4 5 6 7 0 1 2���ҵ����е���СԪ�أ����������в������ظ�Ԫ��
//�ⷨ���������ֲ���

int findMin(std::vector<int> &num)//���м��Ԫ�������ұߵ�Ԫ�رȽϣ��ö��ַ���С��Χ�����Ӷ�ΪO(lgn)
{
	int left = 0, right = num.size() - 1, middle = (left + right) / 2;
	while (left < right)
	{
		if (num[middle] > num[right])
			left = middle + 1;
		else
			right = middle;
		middle = (left + right) / 2;
	}
	return num[left];
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