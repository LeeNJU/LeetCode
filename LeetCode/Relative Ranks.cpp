#include<vector>
#include<string>
#include<algorithm>
//��Ŀ����:����һ�����飬��ʾ�˶�Ա�ķ�������ǰ�������˶�Ա�ֱ���"Gold Medal", "Silver Medal"��"Bronze Medal"
//        �����˶�������Ӧ�����Σ��������[5, 4, 3, 2, 1],����
//        ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"],5����ǽ��ƣ�4�ڶ��������ƣ�2�ǵ�4��
//�ⷨ����:��¼ÿ��Ԫ���Լ���Ӧ���±꣬Ȼ�����򣬷ֱ����Ӧ��ֵ

std::vector<std::string> findRelativeRanks(std::vector<int>& nums) 
{
	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < nums.size(); ++i)
		vec.push_back(std::pair<int, int>(nums[i], i));

	std::sort(vec.begin(), vec.end());
	std::vector<std::string> result(nums.size(), "");
	for (int i = 0; i < (int) vec.size() - 3; ++i)
	{
		std::pair<int, int> p = vec[i];
		result[p.second] = std::to_string(vec.size() - i);
	}

	std::vector<std::string> medals = { "Gold Medal", "Silver Medal", "Bronze Medal" };
	for (int i = (int) vec.size() - 1; i >= 0 && i >= (int) vec.size() - 3; --i)
	{
		std::pair<int, int> p = vec[i];
		result[p.second] = medals[vec.size() - i - 1];
	}

	return result;
}