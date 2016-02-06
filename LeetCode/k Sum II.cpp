#include<vector>
#include<algorithm>
//��Ŀ����:����һ��unique�������һ��k��һ��target��Ҫ���ҵ�����k��Ԫ�ص���ϣ�ʹ�����ǵĺ͵���target
//�ⷨ����:����k sum�����������õݹ�
void dfs(int index, int depth, int k, std::vector<int>& num, std::vector<std::vector<int>>&result, std::vector<int> intermediate, int sum, int target)
{
	if (depth == k) //��ǰ�ݹ����
	{
		if (sum == target) //sum��intermediate����Ԫ�صĺ�
			result.push_back(intermediate);
		return;
	}
	for (int i = index; i < num.size(); ++i)
	{
		if (sum + num[i] > target)
			continue;

		intermediate.push_back(num[i]);
		dfs(i + 1, depth + 1, k, num, result, intermediate, sum + num[i], target);
		intermediate.pop_back();
	}
}


std::vector<std::vector<int> > kSumII(std::vector<int> A, int k, int target)
{
	sort(A.begin(), A.end());
	std::vector<std::vector<int>> result;
	std::vector<int> intermediate;
	dfs(0, 0, k, A, result, intermediate, 0, target);
	return result;
}