#include<vector>
//��Ŀ����������һ�����飬���а������ɸ�0��Ҫ������е�0�ŵ�����ĩβ�����ұ��ַ�0Ԫ�ص����˳�򲻱�
//�ⷨ�������������飬����һ��0�����ҵ�����Ԫ���еķ�0Ԫ�ز���֮����
void moveZeroes(std::vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			int index = i + 1;
			for (; index < nums.size(); ++index) //Ѱ�Һ���Ԫ���еķ�0Ԫ��
			{
				if (nums[index] != 0)
					break;
			}
			if (index == nums.size()) //����Ԫ����û�з�0Ԫ�أ�˵���Ѿ���ɲ���
				return;
			else
				std::swap(nums[i], nums[index]);
		}
	}
}