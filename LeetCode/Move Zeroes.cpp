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
			while (index < nums.size() && nums[index] == 0) //Ѱ�Һ���Ԫ���еķ�0Ԫ��
				++index;

			if (index == nums.size()) //����Ԫ����û�з�0Ԫ�أ�˵���Ѿ���ɲ���
				return;
			else
				std::swap(nums[i], nums[index]);
		}
	}
}