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


//��Ŀ����:Ȩ�ط��������������Ԫ��Ȩ��Ϊ1������[[1,1],3,[1,1]]��1��Ȩ����1,3��Ȩ����2�����Ժ�Ӧ����2 * 3 + 
//        1 * 1 * 4 = 10
//�ⷨ����:����������ȣ�Ȼ����������һ��ķ������
int depthSumInverse(std::vector<NestedInteger>& nestedList) 
{
	int unweighted = 0, weighted = 0;
	while (nestedList.size())
	{
		std::vector<NestedInteger> nextLevel;
		for (auto val : nestedList)
		{
			if (val.isInteger()) 
				unweighted += val.getInteger();
			else
			{
				for (auto v : val.getList()) 
					nextLevel.push_back(v);
			}
			
		}

		weighted += unweighted;
		nestedList = nextLevel;
	}
	return weighted;
}