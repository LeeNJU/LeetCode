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

//version2:������Ű����Ӽ��˳�
//�ⷨ��������һ��stack�������֣���һ��stack��������������õ�һ�����ֲ��ҷ���ջ��ջ��Ԫ���ǳ˺Ż��߳��ŵ�ʱ�򣬽���
//         �˳�������ֱ������ջ��Ԫ�ز��ǳ˳���Ϊֹ���Ѽ�����ѹ������ջ�С�����ѭ������ʱ������ջ�о�ֻ�����Ӽ��š�
//         Ȼ���ջ���Ԫ�ؽ�����ֵ����һ�������ǰѼ��ŵ��ɸ��ţ�����ջ���ֻʣ�Ӻţ������ۼӾͿ�����
int calculate(std::string s)
{
	std::stack<int> num;
	std::stack<char> op;
	int result = 0;
	int sign = 1; //�������ţ���sign��Ϊ-1
	for (int i = 0; i < s.length(); ++i)
	{
		if (isblank(s[i]))
			continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (s[i] == '-')//�������ţ���sign��Ϊ-1�����ҰѼӺ�ѹ��ջ��
			{
				sign = -1;
				op.push('+');
			}
			else
				op.push(s[i]);
		}
		else
		{
			int value = s[i++] - '0';
			for (; i < s.length() && isdigit(s[i]); ++i)//��������
				value = value * 10 + s[i] - '0';
			--i;
			if (op.empty() || (op.top() != '*' && op.top() != '/'))//�������ջΪ�ջ���ջ��Ԫ�ز��ǳ˳��ţ���ջ
			{
				num.push(value * sign);
				sign = 1; //ע������
				continue;
			}
			int t = 0;
			while (!op.empty() && !num.empty() && (op.top() == '*' || op.top() == '/'))
			{
				if (op.top() == '*')
					t += num.top() * value;
				else if (op.top() == '/')
					t += num.top() / value;

				op.pop();
				num.pop();
			}
			num.push(t * sign);
			sign = 1;
		}
	}

	if (op.empty())
		return num.top();

	result = num.top();
	num.pop();
	while (!op.empty()) //����ջ���Ԫ�ؽ����ۼ�
	{
		result += num.top();
		op.pop();
		num.pop();
	}
	return result;
}