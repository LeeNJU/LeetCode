#include<vector>
#include<unordered_set>
//��Ŀ����:����һ���������飬�ҵ���������ʹ�����ǽ����������Ľ����������������[3, 10, 5, 25, 2, 8]��
//        �����������5 ^ 25 = 28������28
//�ⷨ����:�����λ��ʼ����mask�ָ������е�Ԫ��

int findMaximumXOR(std::vector<int>& nums)
{
	int max_val = 0, mask = 0;
	for (int i = 31; i >= 0; i--) 
	{
		mask |= (1 << i);//mask�������������Ԫ�ظ��ݵ�iλ��ֵ���зָ�
		std::unordered_set<int> set;
		for (int num : nums) 
			set.insert(num & mask); // ��������ߵ�λ��mask�տ�ʼΪ1��Ȼ����11��Ȼ����111��Ȼ����1111...

		int tmp = max_val | (1 << i); //�ҵ��Ƿ������������a��b���ڵ�iλ���ǲ�ͬ�ģ�����a ^ b = temp
		for (int prefix : set) 
		{
			if (set.find(tmp ^ prefix) != set.end()) 
				max_val = tmp;
		}
	}
	return max_val;
}