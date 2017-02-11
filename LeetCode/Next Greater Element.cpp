#include<vector>
#include<unordered_map>
#include<stack>
//��Ŀ����:�����������飬���������ظ�Ԫ�أ�nums1 = [4,1,2], nums2 = [1,3,4,2]������nums1�е�Ԫ�أ��ҵ���һ��
//        ���Ԫ�أ�����nums2�У�4֮��û�б�4���Ԫ�أ�������-1,1�����1���Ԫ����3��������3,2����û��Ԫ�أ���
//        ����-1
//�ⷨ����:��stack����һ���ݼ������У�����[9,5,3,1],����һ��Ԫ����4��ʱ��4��1��3��������3��1����һ���Ƚϴ�
//        ��Ԫ����4����hashtable���棬Ȼ���4ѹ��ջ�С�

std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums)
{
	std::stack<int> stack;
	std::unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		while (!stack.empty() && nums[i] > stack.top())
		{
			int val = stack.top();
			stack.pop();
			map[val] = nums[i];
		}

		stack.push(nums[i]);
	}

	std::vector<int> result;
	for (int i = 0; i < findNums.size(); ++i)
	{
		if (map.find(findNums[i]) != map.end())
			result.push_back(map[findNums[i]]);
		else
			result.push_back(-1);
	}

	return result;
}


//�汾2:����ֻ����һ��ѭ�����飬����[1,2,1],��������[2,-1,2]
//�ⷨ����:����һ�����ƣ�ֻ����������±�

std::vector<int> nextGreaterElements(std::vector<int>& nums) 
{
	int n = nums.size();
	std::vector<int> result(n, -1);
	std::stack<int> stack; //���±�
	for (int i = 0; i < n * 2; ++i)//ע��������2 * n
	{
		int num = nums[i % n];
		while (!stack.empty() && nums[stack.top()] < num) 
		{
			result[stack.top()] = num;
			stack.pop();
		}

		if (i < n) 
			stack.push(i);
	}

	return result;
}