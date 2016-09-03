#include<string>
#include<stack>
#include"TreeNode.h"
//��Ŀ����:�����ַ���������ת����NestedInteger,����"[123,[456,[789]]]",
//�ⷨ����:����ջ��ÿ������'['���ʹ�����һ��NestedInteger����ѹ��ջ�У��������֣�������뵽ջ��
//        NestedInteger�У�����']',����ǰջ����NestedInteger�����ˣ�����ջ���������뵽��ǰջ����
//        NestedInteger��

NestedInteger deserialize(std::string s) 
{
	if (s.empty() || s[0] != '[')
		return NestedInteger(stoi(s));

	std::stack<NestedInteger> stack;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '[')
			stack.push(NestedInteger());
		else if (isdigit(s[i]) || s[i] == '-')
		{
			int flag = 1;
			if (s[i] == '-')
			{
				flag = -1;
				++i;
			}

			int num = 0;
			for (; i < s.size() && isdigit(s[i]); ++i)
				num = num * 10 + s[i] - '0';
			--i;

			stack.top().add(NestedInteger(num * flag));
		}
		else if (s[i] == ']')
		{
			if (stack.size() > 1)//ջҪ����1���ܵ�ջ
			{
				NestedInteger n = stack.top();
				stack.pop();
				stack.top().add(n);
			}
		}
	}

	while (stack.size() > 1)
		stack.pop();
	return stack.top();
}