#include<vector>
//��Ŀ����������һ�������һ��ֵ��ɾ�������к͸�ֵ��ȵ�Ԫ�ز�����ɾ��������鳤��
//�ⷨ��index��¼�µ������±꣬i�������飬A[index]��A[i]������Ԫ���ǲ���Ҫɾ����Ԫ�أ�index++�������ȣ�i++��index����

int removeElement(std::vector<int>& nums, int val) 
{
	int index = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
			std::swap(nums[++index], nums[i]);
	}
	return index + 1;
}