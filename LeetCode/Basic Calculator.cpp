#include<string>
#include<stack>
//��Ŀ����������һ���ַ�����ʾ����֮��ļӼ��������������֣��ո����źͼӼ��ţ����������
//�ⷨ������ֱ��ȥ�����Ž��м��㣬��ջ���浱ǰ������ķ���(�����߸�)����resultֱ�Ӽ�����
int calculate(std::string s)
{
	std::stack<int> stack;
	stack.push(1);
	stack.push(1);
	int result = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (isdigit(s[i]))
		{
			int value = 0;
			for (; i < s.size() && isdigit(s[i]); ++i)
				value = value * 10 + s[i] - '0';
			
			--i;
			result += stack.top() * value;//�뵱ǰջ���ķ�����˽��м��㣬���ű�����Ǹ���
			stack.pop();
		}
		else if (s[i] == '+' || s[i] == '(')//�����ӺŻ��������ţ���ջ��Ԫ���ٴ���ջ
			stack.push(stack.top());
		else if (s[i] == '-')//�������ţ�ջ��Ԫ�س���-1
			stack.push(-1 * stack.top());
		else if (s[i] == ')')//���������ţ���ջ
			stack.pop();
	}
	return result;
}