#include<stack>
#include<vector>
#include<string>

//��Ŀ����������沨�����ʽ��ֵ��2 1 + 3 * = 9
//�ⷨ��������ջ�������֣�����������������㣬�ѽ�����浽ջ�У����Ľ������ջ��

bool isOperator(std::string s)
{
	return s.size() == 1 && std::string("+-*/").find(s) != std::string::npos;
}

int evalRPN(std::vector<std::string> &tokens)
{
	std::stack<int> s;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (!isOperator(tokens[i]))
			s.push(stoi(tokens[i]));//stoi��stringת����int
		else//ȡ��ջ����2��Ԫ�أ�����������Ž�������
		{
			int x = s.top();//ע��ȡ��������Ԫ�ص�˳�������ǽ��г������߼�����ʱ��
			s.pop();
			int y = s.top();
			s.pop();
			if (tokens[i] == "+")
				s.push(x + y);
			else if (tokens[i] == "-")
				s.push(y - x);
			else if (tokens[i] == "*")
				s.push(x * y);
			else
				s.push(y / x);
		}
	}
	return s.top();
}