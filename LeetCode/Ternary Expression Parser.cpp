#include<string>
#include<stack>
//��Ŀ����:����һ����Ŀ���ʽ���������յĽ�������� T ? 4 : 5,����4�����ֶ���0��9�����֣�T��ʾtrue��F��ʾ
//        false�����ʽ����Ƕ�ף�����F ? 1 : T ? 4 : 5������4
//�ⷨ����:��ջ���������ÿ����һ�����Խ����ĺϸ����Ŀ���ʽ�ͽ���������ѽ���Ż�ջ�У�

std::string parseTernary(std::string expression) 
{
	if (expression.empty()) 
		return "";
	
	std::stack<char> stack;
	for (int i = expression.length() - 1; i >= 0; i--) 
	{
		if (!stack.empty() && stack.top() == '?') //�����ϸ����Ŀ���ʽ����������ѹ��ջ��
		{
			stack.pop(); //pop '?'
			char first = stack.top();
			stack.pop(); //pop ':'
			char second = stack.top();
			stack.pop();

			if (expression[i] == 'T') 
				stack.push(first);
			else 
				stack.push(second);
		}
		else 
			stack.push(expression[i]);
	}

	return std::string(1, stack.top());
}