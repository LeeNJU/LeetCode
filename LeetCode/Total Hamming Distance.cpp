#include<vector>
//��Ŀ����:����һ���������飬���ÿ������֮���hemming distance������[4, 14, 2],����֮���hemming distance
//        ��(4, 14) + (4, 2) + (14, 2) = 2 + 2 + 2 = 6.Hemming disance��λ����ͬ�ĸ���
//�ⷨ����:��ÿ�����ĵ�iλ��ͳ���ж��ٸ�0�����ٸ�1��n��0��m��1����ô����n * m��hemming distance

int totalHammingDistance(std::vector<int>& nums) 
{
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		int bit_count = 0;
		for (int j = 0; j < nums.size(); ++j)
		{
			bit_count += ((nums[j] >> i) & 1);
		}

		result += bit_count * (nums.size() - bit_count);
	}
	return result;
}