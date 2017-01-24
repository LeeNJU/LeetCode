#include<vector>
#include<stack>
#include<algorithm>
//��Ŀ����:����һ�����飬�����Ǹ���������ʾÿ�������εĸ߶ȣ���ȶ���1������Щ�����ε�������
//�ⷨ����:��һ��ջ��¼�����γ��ȵ��±꣬�����ǰԪ�ر�ջ���±�ĳ����θ߶ȸ߻���ջΪ�գ���ô�±���ջ���õ�
//        �������±����У������ǰ�߶ȱ�ջ���ĳ����θ߶ȵͣ��ҵ�ǰ���һ���ȵ�ǰ�߶ȵ͵ĳ����Σ�������������
//        ����֮��ĳ����ε�����������������������Σ�
//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html

int largestRectangleArea(std::vector<int>& heights)
{
	std::stack<int> stack;
	heights.push_back(0);//����߶�Ϊ0��bar����Ϊ�˼������ĵ������е����

	int sum = 0;
	int i = 0;
	while (i < heights.size())
	{
		if (stack.empty() || heights[i] > heights[stack.top()]) //��ǰ�߶ȱ�ջ��Ԫ��С����ջΪ��
		{
			stack.push(i);
			++i;
		}
		else
		{
			while (!stack.empty() && heights[stack.top()] >= heights[i])//ͳ��֮ǰ�ĵ��������γɵ�������
			{
				int t = stack.top();//ע������߶�����heights[t]
				stack.pop();
				sum = std::max(sum, heights[t] * (stack.empty() ? i : i - stack.top() - 1));
			}

			stack.push(i);
			++i;
		}
	}
	return sum;
}