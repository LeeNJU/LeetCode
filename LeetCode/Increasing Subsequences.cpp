#include<vector>
#include<unordered_set>
//��Ŀ����:����һ�����飬�ҵ�������������еĳ��ȴ��ڵ���2�ĵ��������У�����[4, 6, 7, 7]������
//        [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//�ⷨ����:�ݹ���⣬

void dfs(std::vector<std::vector<int>>& result, const std::vector<int>& nums, std::vector<int>& t, int index)
{
	if (t.size() >= 2)
		result.push_back(t);

	std::unordered_set<int> set;//����û������������set��ȥ��
	for (int i = index; i < nums.size(); ++i)
	{
		if ((t.empty() || nums[i] >= t.back()) && set.find(nums[i]) == set.end())
		{         //�����ǵ������У��Ҳ����ظ��ļ�ͬһ��Ԫ��
			set.insert(nums[i]);
			t.push_back(nums[i]);
			dfs(result, nums, t, i + 1);
			if (!t.empty())
				t.pop_back();
		}
	}
}


std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) 
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, nums, t, 0);
	return result;
}