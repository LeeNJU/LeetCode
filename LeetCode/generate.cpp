#include<vector>
//��Ŀ����������һ������n��������Ӧ����˹��������
//�ⷨ�������õ���һ�е�ֵ��һ�μ�����һ�е�ֵ

std::vector<std::vector<int> > generate(int numRows)
{
	std::vector<std::vector<int>> result;
	if (numRows == 0) 
		return result;
	result.push_back(std::vector<int>(1, 1)); //first row
	
	for (int i = 2; i <= numRows; ++i) 
	{
		std::vector<int> current(i, 1); // ����
		const std::vector<int> &prev = result[i - 2]; // ��һ��
		for (int j = 1; j < i - 1; ++j) 
			current[j] = prev[j - 1] + prev[j]; // ���ϽǺ����Ͻ�֮��
		result.push_back(current);
	}
	return result;
}

