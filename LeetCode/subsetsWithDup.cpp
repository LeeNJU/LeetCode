#include<vector>
#include<algorithm>

//��Ŀ����������һ�����飬�����ظ�Ԫ�أ����������������Ӽ����Ӽ��в��ܰ����ظ����Ӽ��� ����[1,2,2],�Ӽ�Ϊ[[2],[1],[1, 2, 2],[2, 2],[1, 2],[]]
//�ⷨ�������ݹ飬ע��ȥ���ظ�Ԫ��

void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, const std::vector<int>& nums, int index)
{
	result.push_back(t);

	for (int i = index; i < nums.size(); ++i)
	{
		if (i > index && nums[i] == nums[i - 1])//�ж��Ƿ���ǰһ��Ԫ���ظ�������ظ�����ֱ�ӽ�����һ��ѭ��
			continue;

		t.push_back(nums[i]);
		dfs(result, t, nums, i + 1);
		t.pop_back();//��ҪҪ����һ��Ԫ��
	}
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());//ע��Ҫ����
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, nums, 0);
	return result;
}