#include<vector>
#include<algorithm>
//��Ŀ����������һ���������ϣ�{1,2,3}��������е��Ӽ�������ÿ���Ӽ���Ԫ���Ե���˳�򣬽����{{3},{2},{1},{1,3},{2,3},{1,2},{1,2,3},{}}�������˿ռ�
//�ⷨ���ݹ�

std::vector<std::vector<int> > subsets(std::vector<int> &S)
{
	sort(S.begin(), S.end());
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	subset(S, result, path, 0);
	return result;
}

void subset(const std::vector<int>& S, std::vector<std::vector<int>>& result, std::vector<int>& path, int depth)
{
	if (depth == result.size())
	{

	}
}
