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
//�ⷨ����:��һ��stack�������֣���һ��stack��������������õ�һ�����ֲ��ҷ���ջ��ջ��Ԫ���ǳ˺Ż��߳��ŵ�ʱ
//        �򣬽��г˳�������ֱ������ջ��Ԫ�ز��ǳ˳���Ϊֹ���Ѽ�����ѹ������ջ�С�����ѭ������ʱ������ջ��
//        ��ֻ�����Ӽ��š�Ȼ���ջ���Ԫ�ؽ�����ֵ����һ�������ǰѼ��ŵ��ɸ��ţ�����ջ���ֻʣ�Ӻţ������ۼ�
//        �Ϳ�����
int calculate2(std::string s)
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

//��׺���ʽ��ֵ:һ��ջװ���֣�һ��ջ���������������ջ����������ջ�����������������ջ�������������ȼ����ڵ���
//             ��ǰ�����������ȼ����Ͷ�ջ�����������в�����ֱ��ջ�����������ȼ����ڵ�ǰ��������Ȼ��ѵ�ǰ
//             ��������ջ�������ǰ�����������ȼ������ʹ���ջ����������ֱ����ջ���������)����Ҫ�������е�ֵ
//             ������ֵ��ֱ������������
/*
int get_priority(char c)
{
	if (c == '+')
		return 1;
	else if (c == '-')
		return 1;
	else if (c == '*')
		return 2;
	else if (c == '/')
		return 2;
	else if (c == '(')
		return 0;
	else if (c == ')')
		return 3;
	return -1;
}

void calculate(stack<int>& operand, stack<char>& ops)
{
	int num1 = operand.top();
	operand.pop();
	int num2 = operand.top();
	operand.pop();
	if (ops.top() == '+')
		operand.push(num1 + num2);
	else if (ops.top() == '-')
		operand.push(num2 - num1);
	else if (ops.top() == '*')
		operand.push(num1 * num2);
	else if (ops.top() == '/')
		operand.push(num2 / num1);
}

int calculate(string s)
{
	stack<int> operand;
	stack<char> ops;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
			continue;
		else if (isdigit(s[i]))
		{
			int val = 0;
			while (i < s.length() && isdigit(s[i]))
				val = val * 10 + s[i++] - '0';

			operand.push(val);
			--i;
		}
		else if (s[i] == '(')
			ops.push('(');
		else if (s[i] == ')')
		{
			while (ops.top() != '(')
			{
				calculate(operand, ops);
				ops.pop();
			}
			ops.pop();
		}
		else
		{
			int priority = get_priority(s[i]);
			if (ops.empty() || priority > get_priority(ops.top()))
			{
				ops.push(s[i]);
				continue;
			}

			while (!ops.empty() && priority <= get_priority(ops.top()))
			{
				calculate(operand, ops);
				ops.pop();
			}
			ops.push(s[i]);
		}
	}

	while (!ops.empty())
	{
		calculate(operand, ops);
		ops.pop();
	}

	return operand.top();
}*/