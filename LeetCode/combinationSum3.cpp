#include<vector>

//��Ŀ����������һ��ֵk��n����1��9�������Ϊn����ϣ���ϵĴ�СΪk�����ֲ����ظ������磺k=3��n=7�����Ϊ[[1,2,4]]
//�ⷨ�������ݹ�  0ms


void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, int index, int k, int value)
{
	if (t.size() == k)
	{
		if (value == 0)
			result.push_back(t);
		return;
	}

	for (int i = index; i < 10; ++i)
	{
		if (i <= value)
		{
			t.push_back(i);
			dfs(result, t, i + 1, k, value - i);
			t.pop_back();//ע����� Ҫ����һ��Ԫ��
		}
	}
}

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, 1, k, n);
	return result;
}