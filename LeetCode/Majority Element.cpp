#include<vector>

//��Ŀ����������һ�����飬�䳤��Ϊn���ҵ����г��ִ�������n/2��Ԫ�أ���������ǿգ�����һ������������Ԫ��
//�ⷨ��������candidate��ʾ���Ľ����count��ʾcandidate���ֵĴ������������飬���count���ڣ���ôcandidateΪnums[i]��count��1�����count������0
//���candidate����nums[i]����ôcount��1�����candidate������nums[i]���Ͱ�count��1�����candidate�������Ҫ�ҵ�Ԫ�أ���ôһ���������㹻�������
//Ԫ��ʹ�����candidate��countΪ0�����candidate�������Ҫ�ҵ�Ԫ�أ���ôcandidate��count����٣����������0

int majorityElement(std::vector<int>& nums)
{
	int candidate = 0, count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (count == 0)
		{
			candidate = nums[i];
			++count;
		}
		else
		{
			if (candidate == nums[i])
				++count;
			else
				--count;
		}
	}
	return candidate;
}