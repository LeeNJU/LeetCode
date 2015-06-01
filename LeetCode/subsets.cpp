#include<vector>
#include<algorithm>
//��Ŀ����������һ���������ϣ�{1,2,3}��������е��Ӽ�������ÿ���Ӽ���Ԫ���Ե���˳�򣬽����{{3},{2},{1},{1,3},{2,3},{1,2},{1,2,3},{}}�������˿ռ�
//�ⷨ���ݹ飬ÿһ��ݹ����һ��Ԫ�ص�t�У�����t���뵽result��

void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, const std::vector<int>& nums, int index)//index��ʾ��ʼ���±�
{
	result.push_back(t);

	for (int i = index; i < nums.size(); ++i)
	{
		t.push_back(nums[i]);
		dfs(result, t, nums, i + 1);
		t.pop_back();
	}
}


std::vector<std::vector<int> > subsets(std::vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	dfs(result, path, nums, 0);
	return result;
}

