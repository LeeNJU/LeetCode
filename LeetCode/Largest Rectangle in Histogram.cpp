#include<vector>
#include<stack>
#include<algorithm>
//��Ŀ����������һ�����飬�����Ǹ���������ʾÿ�������εĸ߶ȣ���ȶ���1������Щ�����ε�������
//�ⷨ��������һ��ջ��¼�����γ��ȵ��±꣬�����ǰԪ�ر�ջ���±�ĳ����θ߶ȸ߻���ջΪ�գ���ô�±���ջ���õ��������±����У������ǰ�߶ȱ�ջ���ĳ�����
//         �߶ȵͣ��ҵ�ǰ���һ���ȵ�ǰ�߶ȵ͵ĳ����Σ�����������������֮��ĳ����ε�����������������������Σ�

int largestRectangleArea(std::vector<int>& height)
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