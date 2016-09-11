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
			dfs(result, temp, visited, num);
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


//��Ŀ����������һ���������飨�����ظ�Ԫ�أ���������Щ�������е����
//�ⷨ�������ݹ飬��������һ��visited���鱣��Ԫ���Ƿ񱻱�����������ظ�Ԫ�ؾ�������

void dfs(std::vector<int>& num, std::vector<bool>& visited, std::vector<int>& solution, std::vector<std::vector<int>>& result)
{
	if (solution.size() == num.size())//�ҵ�һ����
	{
		result.push_back(solution);
		return;
	}
	for (int i = 0; i< num.size(); i++)//ÿ�ζ��Ǵ�0��ʼ����
	{
		if (visited[i] == false)//Ԫ��û�б����ʹ��ż��뵽solution��
		{
			if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == false)//ע������visited[i - 1]������false����
				continue;                                                //continue
			visited[i] = true;
			solution.push_back(num[i]);
			dfs(num, visited, solution, result);
			solution.pop_back();
			visited[i] = false;
		}
	}
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
	std::vector<std::vector<int> > result;
	std::vector<int> perm;
	std::vector<bool> visited(nums.size(), 0);
	std::sort(nums.begin(), nums.end());  //�Ƚ������򣬷���ȥ��
	dfs(nums, visited, perm, result);
	return result;
}