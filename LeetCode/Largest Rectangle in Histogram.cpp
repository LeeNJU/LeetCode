#include<vector>
#include<stack>
#include<algorithm>
//��Ŀ����������һ�����飬�����Ǹ���������ʾÿ�������εĸ߶ȣ���ȶ���1������Щ�����ε�������
//�ⷨ��������һ��ջ��¼�����γ��ȵ��±꣬�����ǰԪ�ر�ջ���±�ĳ����θ߶ȸ߻���ջΪ�գ���ô�±���ջ���õ��������±����У������ǰ�߶ȱ�ջ���ĳ�����
//         �߶ȵͣ��ҵ�ǰ���һ���ȵ�ǰ�߶ȵ͵ĳ����Σ�����������������֮��ĳ����ε�����������������������Σ�

int largestRectangleArea(std::vector<int>& height)
{
	int area = 0;
	std::stack<int> stack;
	for (int i = 0; i < height.size(); ++i) 
	{
		if (stack.empty() || height[stack.top()] < height[i]) //��ջ�����ǵ������У���ô��ջ
			stack.push(i);
		else 
		{
			int start = stack.top(); //����ջ��Ԫ�أ��������
			stack.pop();
			int width = stack.empty() ? i : i - stack.top() - 1;
			area = std::max(area, height[start] * width);
			i--;  //ע������i--����Ϊ�˼���ǰ��ĳ������������һ���м���
		}
	}
	while (!stack.empty()) //ջ��Ϊ�գ�˵���������ļ���Ԫ�ظպ��ǵ������У���ô���μ���
	{
		int start = stack.top();
		stack.pop();
		int width = stack.empty() ? height.size() : height.size() - stack.top() - 1;
		area = std::max(area, height[start] * width);
	}
	return area;
}