#include<vector>
//��Ŀ����:����һ����n���ҵ������е���������ϣ�����12������[[2, 6],[2, 2, 3],[3, 4]],�����������1С��n
//�ⷨ����:�ݹ����
void dfs(std::vector<std::vector<int>>& result, std::vector<int> t, int product, int last, int num)
{                             //last����һ���õ�������product�ǵ���һ�����������ĳ˻�
	if (product > num || last > num)//�˻���num�������һ���õ�������num��
		return;

	if (product == num)
	{
		result.push_back(t);
		return;
	}

	for (int i = last; i < num; ++i)
	{
		if (num % (i * product) == 0)//����������
		{
			t.push_back(i);
			dfs(result, t, product * i, i, num);
			t.pop_back();
		}
	}
}

std::vector<std::vector<int>> getFactors(int n)
{
	std::vector<std::vector<int>> result;
	std::vector<int> t;
	dfs(result, t, 1, 2, n);
	return result;
}