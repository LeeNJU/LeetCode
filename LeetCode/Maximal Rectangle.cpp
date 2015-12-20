#include<vector>
#include<algorithm>
//��Ŀ����:����һ������ȫ��0��1���ҵ�һ�����Σ��������ȫ����1������������
//�ⷨ����:���ÿһ�еĸ߶ȣ�Ȼ��ÿһ�а���Largest Reatangle �Ľⷨ���
int largestRectangleArea(std::vector<int> height)
{
	std::vector<int> s;
	height.push_back(0);//����߶�Ϊ0��bar����Ϊ�˼������ĵ������е����

	int sum = 0;
	int i = 0;
	while (i < height.size())
	{
		if (s.empty() || height[i] > height[s.back()]) //��ǰ�߶ȱ�ջ��Ԫ��С����ջΪ��
		{
			s.push_back(i);
			i++;
		}
		else
		{
			int t = s.back();
			s.pop_back();
			//���ﻹ��Ҫ����stackΪ�յ����
			sum = std::max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
		}
	}
	return sum;
}

int maximalRectangle(std::vector<std::vector<char>>& matrix) 
{
	if (matrix.empty())
		return 0;

	std::vector<std::vector<int>> height(matrix.size(), std::vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == '0')
				height[i][j] = 0;
			else
				height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
		}
	}

	int max_area = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		max_area = std::max(max_area, largestRectangleArea(height[i]));
	}
	return max_area;
}