#include<vector>
#include<algorithm>
//��Ŀ����������һ�����飬�������ظ�Ԫ�أ����������������е���������
//�ⷨ�������ݹ����,��һ��visited���鱣��Ԫ���Ƿ񱻷��ʹ�

void dfs(std::vector<std::vector<int>>& result, std::vector<int> temp, std::vector<bool>& visited, const std::vector<int>& num)
{
	if (temp.size() == num.size())
	{
		result.push_back(temp);
		return;
	}

	for (int i = 0; i < num.size(); ++i)//����ɨ�裬ÿһ��ݹ�ֻ����һ��Ԫ�أ�����Ҫpop_back
	{
		if (!visited[i])
		{
			visited[i] = true;
			temp.push_back(num[i]);
			dfs(result, temp, visited,num);
			temp.pop_back();//һ��ݹ�ֻ����һ��Ԫ��
			visited[i] = false;
		}
	}
}

std::vector<std::vector<int> > permute(std::vector<int>& num)
{
	std::vector<std::vector<int> > result;
	std::vector<int> temp;
	std::vector<bool> visited(num.size(), false);
	dfs(result, temp, visited, num);
	return result;
}
