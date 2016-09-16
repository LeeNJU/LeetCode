#include<string>
#include<stack>
//��Ŀ����:���ַ������н��룬�ַ����ĸ�ʽΪk[encoded_string]��k�����֣������ڵ��ַ������������֣�����
//        "2[abc]3[cd]ef",����֮����"abcabccdcdcdef"��"3[a2[c]]"����֮����"accaccacc"�����ſ���Ƕ�ס�
//�ⷨ����:������ջ������ջ����ǰ������֣��ַ���ջ��������֮����ַ�����������ջ����������ջ�������������ţ�
//        ȡ���ַ���ջ�е��ַ�������ƴ�ӣ�ֱ�����������ţ�Ȼ���ظ�һ����������ѹ���ַ���ջ��

std::string decodeString(std::string s)
{
	std::stack<int> num;
	std::stack<std::string> stack;
	std::string result = "";

	for (int i = 0; i < s.size();)
	{
		if (isdigit(s[i]))//ȡ�����֣���������ջ��
		{
			int index = i;
			while (isdigit(s[index]))
				++index;

			num.push(stoi(s.substr(i, index - i)));
			i = index;
		}
		else if (s[i] == '[')//��������ջ
		{
			stack.push("[");
			++i;
		}
		else if (isalpha(s[i]))//�ҵ���ǰ�ַ������������ַ���ջ
		{
			int index = i;
			while (index < s.size() && isalpha(s[index]))
				++index;

			stack.push(s.substr(i, index - i));
			i = index;
		}
		else//����������
		{
			std::string str = "";
			while (stack.top() != "[")//�ѵ�ǰ�����ڵ��ַ����ϲ���һ���ַ���
			{
				str = stack.top() + str;
				stack.pop();
			}
			stack.pop();

			int val = num.top();
			num.pop();
			std::string temp = "";
			while (val > 0)//ȡ������ջ�е����֣��ظ��ַ���
			{
				--val;
				temp += str;
			}

			stack.push(temp);//�õ����ַ���ѹ��ջ��
			++i;
		}
	}

	while (!stack.empty() && stack.top() != "[")//���ַ���ջ�е��ַ���ƴ������
	{
		result = stack.top() + result;
		stack.pop();
	}

	return result;
}