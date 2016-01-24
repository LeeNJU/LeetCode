#include<vector>
#include<algorithm>
//��Ŀ����������һ�������������һ��������s�����������ҵ��ʹ��ڵ���s����С������ĳ���,����[2,3,1,2,4,3]��
//         s = 7����С����Ϊ[4,3]
//�ⷨ��������left��right����ָ��ά����������飬sumΪ������ĺͣ������ƶ�right��ֱ��sum���ڵ���s��Ȼ��ѭ��ȥ�����������߲���

int minSubArrayLen(int s, std::vector<int>& nums)
{
	int min_length = nums.size() + 1, sum = 0;//��min_length���һ���Ƚϴ��ֵ����������Ƚ�
	int left = 0, right = 0;
	while (right < nums.size())
	{
		sum += nums[right];
		if (sum >= s)//sumһ������s���������ٴ���һ����
		{
			while (sum - nums[left] >= s)//ȥ����߶����Ԫ�أ�left�����ƶ�
			{
				sum -= nums[left];
				++left;
			}
			min_length = std::min(min_length, right - left + 1);
		}
		++right;
	}
	return min_length == nums.size() + 1 ? 0 : min_length;//���min_lengthΪ��ʼֵ��˵���޽⣬����0
}