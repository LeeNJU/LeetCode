#include<vector>
#include<algorithm>
//��Ŀ����:����һ���������飬�������wiggle sequence�ĳ��ȣ�wiggle sequenceҪ�ϸ���������������
//        [1,7,4,9,2,5]������һ��wiggle sequence����[1,4,7,2,5]���ǡ������п��ܴ��ڶ��һ������wiggle
//        sequence,������������һ����ġ�
//�ⷨ����:̰���㷨����p��ǰԪ���ǵ����ĳ��ȣ�q��ʾ��ǰԪ���ǵݼ��ĳ��ȣ������ǰԪ�ر�ǰһ��Ԫ�ش���ôp����
//        q + 1, �����ǰԪ�ر�ǰһ��Ԫ��С����ôq����p + 1

int wiggleMaxLength(std::vector<int>& nums) 
{
	int p = 1, q = 1, n = nums.size();
	for (int i = 1; i < n; ++i) 
	{
		if (nums[i] > nums[i - 1]) 
			p = q + 1;
		else if (nums[i] < nums[i - 1]) 
			q = p + 1;
	}
	return std::min(n, std::max(p, q));
}