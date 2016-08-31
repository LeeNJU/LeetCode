#include<vector>
#include<unordered_map>

//��Ŀ����������һ�����飬�䳤��Ϊn���ҵ����г��ִ�������n/2��Ԫ�أ���������ǿգ�����һ������������Ԫ��
//�ⷨ��������candidate��ʾ���Ľ����count��ʾcandidate���ֵĴ������������飬���count����0����ôcandidate
//         Ϊnums[i]��count��1�����count������0����candidate����nums[i]����ôcount��1�����candidate����
//         ��nums[i]���Ͱ�count��1�����candidate�������Ҫ�ҵ�Ԫ�أ���ôһ���������㹻�������Ԫ��ʹ�����
//         candidate��countΪ0�����candidate�������Ҫ�ҵ�Ԫ�أ���ôcandidate��count����٣����������0

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

//��Ŀ����:�ҵ������г��ִ�������n / 3��Ԫ��
//�ⷨ����:���������Ԫ�س��ֵĴ�������n / 3���ⷨ������һ��
std::vector<int> majorityElement2(std::vector<int>& nums) 
{
	std::vector<int> result;

	int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == candidate1) //ע������������жϵ�ǰԪ���ǲ���������candidateԪ�����
			++count1;
		else if (nums[i] == candidate2)
			++count2;
		else if (count1 == 0)
		{
			++count1;
			candidate1 = nums[i];
		}
		else if (count2 == 0)
		{
			++count2;
			candidate2 = nums[i];
		}
		else
		{
			--count1;
			--count2;
		}
	}

	count1 = 0;
	count2 = 0;
	for (int i = 0; i < nums.size(); ++i) //��֤����candidateԪ�صĳ��ִ�����ȷ����n / 3
	{
		if (nums[i] == candidate1)
			++count1;
		else if (nums[i] == candidate2)
			++count2;
	}

	if (count1 > nums.size() / 3)
		result.push_back(candidate1);
	if (count2 > nums.size() / 3)
		result.push_back(candidate2);
	return result;
}

//��Ŀ����������һ�������һ��ֵk���ҵ������г��ִ�������n/k��Ԫ��
//�ⷨ��������hashtable��¼ÿ��Ԫ�س��ֵĴ���

int majorityNumber(std::vector<int> nums, int k)
{
	std::unordered_map<int, int> m;
	int count = nums.size() / k;
	for (int i = 0; i < nums.size(); ++i)
	{
		++m[nums[i]];
		if (m[nums[i]] > count)
			return nums[i];
	}
}