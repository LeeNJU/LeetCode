#include<vector>
#include<algorithm>
//��Ŀ����:����һ��unique�������һ��k��һ��target��Ҫ���ҵ�����k��Ԫ�ص���ϣ�ʹ�����ǵĺ͵���target
//�ⷨ����:����k sum�����������õݹ�
void dfs(int index, int k, std::vector<int>& num, std::vector<std::vector<int>>&result, 
	std::vector<int> intermediate, int target)
{
	if (k == 0)
	{
		if (target == 0)
			result.push_back(intermediate);
		return;
	}
	for (int i = index; i < num.size(); ++i)
	{
		if (target < num[i])
			break;

		intermediate.push_back(num[i]);
		dfs(i + 1, k - 1, num, result, intermediate, target - num[i]);
		intermediate.pop_back();
	}
}

std::vector<std::vector<int> > kSumII(std::vector<int> A, int k, int target) 
{
	sort(A.begin(), A.end());
	std::vector<std::vector<int>> result;
	std::vector<int> intermediate;
	dfs(0, k, A, result, intermediate, target);
	return result;
}