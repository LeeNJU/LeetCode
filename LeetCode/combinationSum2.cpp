#include<vector>
#include<algorithm>
#include<numeric>

//��Ŀ����������һ�������һ��ֵ���ҵ����������к͵��ڸ�ֵ��Ԫ�ص���ϣ�ÿ��Ԫ��ֻ��ʹ��һ��
//�ⷨ�������������ٵݹ飬ע������ظ�
void dfs(std::vector<std::vector<int>>& result, const std::vector<int>& num, std::vector<int> temp, int index, int target)
{
	int sum = std::accumulate(temp.begin(), temp.end(), 0);
	if (sum == target)
	{
		result.push_back(temp);
		return;
	}
	if (sum > target)
		return;

	int prev = -1;
	for (int i = index; i < num.size(); ++i)
	{
		if (prev == num[i])//ȥ���ظ�Ԫ�أ�������ظ��������������ע��ע�⣡��
			continue;
		prev = num[i];
		temp.push_back(num[i]);
		dfs(result, num, temp, i + 1, target);
		temp.pop_back();
	}
}

std::vector<std::vector<int> > combinationSum2(std::vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	std::vector<std::vector<int>> result;
	std::vector<int> temp;
	dfs(result, num, temp, 0, target);
	return result;
}