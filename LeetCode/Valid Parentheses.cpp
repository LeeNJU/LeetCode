#include<iostream>
#include<string>
#include<stack>

//��Ŀ����:����һ���ַ�����ֻ����([{)]}�����ַ����ж��Ƿ�����Ч���ַ�������(),[],{}����Ч�ģ�(],([)]�ȶ���
//        ��Ч��
//�ⷨ����:��һ��ջ��([[ѹ��ջ�У�����)]}ʱ���ж���ջ��Ԫ���Ƿ�����

bool isValid(std::string s)
{
	if (s.length() % 2 != 0)//���������ֱ�ӷ���false
		return false;

	std::stack<char> stack;//��ջ��¼֮ǰ�ķ���
	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push(s[i]);
		else if (s[i] == ')')
		{
			if (stack.empty() || stack.top() != '(')//Ҫ�ж�ջ�Ƿ�Ϊ��
				return false;
			stack.pop();
		}
		else if (s[i] == ']')
		{
			if (stack.empty() || stack.top() != '[')
				return false;
			stack.pop();
		}
		else
		{
			if (stack.empty() || stack.top() != '{')
				return false;
			stack.pop();
		}
	}
	
	return stack.empty();//ѭ�����������ջ��Ϊ�գ���Ϊfalse
}

