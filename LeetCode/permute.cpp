#include<vector>
#include<algorithm>


void dfs(std::vector<std::vector<int>>& result, std::vector<int> temp, const std::vector<int>& num)
{
	if (temp.size() == num.size())
	{
		result.push_back(temp);
		return;
	}

	for (int i = 0; i < num.size(); ++i)//����ɨ�裬ÿһ��ݹ�ֻ����һ��Ԫ�أ�����Ҫpop_back
	{
		if (std::find(temp.begin(), temp.end(), num[i]) == temp.end())
		{
			temp.push_back(num[i]);
			dfs(result, temp, num);
			temp.pop_back();//һ��ݹ�ֻ����һ��Ԫ��
		}
	}
}

std::vector<std::vector<int> > permute(std::vector<int>& num)
{
	std::vector<std::vector<int> > result;
	std::vector<int> temp;
	dfs(result, temp, num);
	return result;
}
