#include<vector>
//��Ŀ����:����һ�����֣������ظ�Ԫ�أ����������е�һ��Ԫ�أ�����������Ԫ�ص���һһ���±꣬����
//        {1,2,3,3,3},��������3������3���±�2,3����4����������һ���±꣬ÿ���±걻ѡ�еĸ�����ͬ
//�ⷨ����:reservoir sampling.ɨ�����飬��count��¼target���ֵĸ�����ÿ���ҵ�һ��target���֣���ȡģ�����
//        ���Ϊ0���͸�ֵ

class Solution 
{
private:
	std::vector<int> vec;
public:
	Solution(std::vector<int> nums) :vec(nums){}

	int pick(int target) 
	{
		int count = 0, result = -1;
		for (int i = 0; i < vec.size(); ++i) 
		{
			if (vec[i] == target)
			{
				++count;
				if (rand() % count == 0)//ע��������ﱣ֤ÿ��index�ĸ������
					result = i;
			}
		}
		return result;
	}
};