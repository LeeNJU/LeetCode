#include<vector>
//��Ŀ����:����һ�����飬������д������ţ�ʹ��ÿһ�����еĿ����Զ�����ͬ�ġ�
//�ⷨ����:������������������Ե�i��λ�õ�Ԫ�أ�����һ������±꣬�õ����λ�õ�Ԫ�أ�i��1��������ķ�Χ��֮
//        ��С��

class Solution 
{
private:
	std::vector<int> vec;
public:
	Solution(std::vector<int> nums) 
	{
		this->vec = nums;
	}

	/** Resets the array to its original configuration and return it. */
	std::vector<int> reset() 
	{
		return vec;
	}

	/** Returns a random shuffling of the array. */
	std::vector<int> shuffle() 
	{
		std::vector<int> result(vec);
		for (int i = 0; i < vec.size(); ++i)
		{
			int index = rand() % (vec.size() - i);//������ķ�Χ��֮��С
			std::swap(result[i], result[i + index]);//�õ�����±꣬����ǰԪ����֮����
		}
		return result;
	}
};