#include<vector>
#include<algorithm>
//��Ŀ����:����һ�������һ��target���ҵ�����������ϣ�ʹ�����������ĺ�С��target����������ϵĸ���
//�ⷨ����:������������3sum�Ľⷨ
int threeSumSmaller(std::vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());
	int count = 0;
	for (int i = 0; i < nums.size() - 1; ++i) 
	{
		int left = i + 1, right = nums.size() - 1;
		while (left < right) 
		{
			if (nums[i] + nums[left] + nums[right] >= target) 
				--right;
			else 
			{
				count += (right - left);//ע������ҵ�һ����֮�����������Сright����Ȼ��һ����
				++left;
			}
		}
	}
	return count;
}