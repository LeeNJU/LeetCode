#include<vector>
#include<algorithm>
//��Ŀ����:����һ�����飬����һ��move������move�����������е�n - 1��Ԫ������1���߼���1����������Ҫ���ٸ�move
//        ����������ʹ�������е�Ԫ��ȫ����ȡ�����[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4].������Ҫ
//        3������
//�ⷨ����:��n - 1��Ԫ�ؼ�1���൱�ڶ�����Ԫ�ؼ�1�����ҵ���С��Ԫ�أ�Ȼ���ۼ�����Ԫ������СԪ�صĲ�

int minMoves(std::vector<int>& nums) 
{
	if (nums.size() <= 1)
		return 0;

	int min = *min_element(nums.begin(), nums.end());
	int count = 0;
	for (int val : nums)
		count += (val - min);

	return count;
}