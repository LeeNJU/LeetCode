#include<algorithm>
#include<vector>
//��Ŀ����������һ��δ��������飬�����ҳ���һ��missing������������[3,4,-1,1]����ô��һ��missing��������2��
//�ⷨ������˼·���ǰ�Ԫ�ط�����ʵ�λ�ã�����1�ŵ�0λ�ã�2�ŵ�1λ��...�������飬��Ԫ�ض��ŵ����ʵ�λ�ã��ٱ��������ҵ���һ��û�зŵ�����λ�õ�Ԫ��

int firstMissingPositive(std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); ++i) //�������飬������Ԫ�ض�������ʵ�λ��
	{
		while (nums[i] != i + 1) //����ĳһ��Ԫ��Ϊ�ŵ����ʵ�λ��
		{
			if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])//����Ԫ���Ǹ�������������鳤�ȣ��������λ���ϵ�Ԫ�����
				break;
			std::swap(nums[i], nums[nums[i] - 1]);//�Ѹ�Ԫ�طŵ����ʵ�λ��
		}
	}

	for (int i = 0; i < nums.size(); ++i)//�������飬�ҵ���һ��û�зŵ�����λ�õ�Ԫ�أ���nums[i] != i + 1
	{
		if (nums[i] != (i + 1))
			return i + 1;
	}
	
	return nums.size() + 1;
}