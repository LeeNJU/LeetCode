#include"TreeNode.h"
#include<vector>
//��Ŀ����:����һ��Ƕ�׵��������Ԫ�صĺͣ�����[1,[4,[6]]]����27����Ϊ1�������1,4�������2,6�������3������
//        ����1 * 1 + 2 * 4 + 6 * 3 = 27.
//�ⷨ����:�ݹ飬�жϵ�ǰԪ���Ƿ���һ����������һ������Ȼ�����������

int dfs(std::vector<NestedInteger>& nestedList, int depth) 
{
	int sum = 0;
	for (auto element : nestedList)
	{
		if (element.isInteger())
			sum += element.getInteger() * depth;
		else
		{
			std::vector<NestedInteger> t = element.getList();
			sum += dfs(t, depth + 1);
		}
	}
	return sum;
}

int depthSum(std::vector<NestedInteger>& nestedList) 
{
	return dfs(nestedList, 1);
}
