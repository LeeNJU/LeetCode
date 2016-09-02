#include<string>
#include<stack>
#include<algorithm>
//��Ŀ����������һ��ֻ����()���ַ������ҵ������Ч�ַ����������䳤�ȣ�()Ϊ��Ч�ַ���
//�ⷨ��������һ��ջ��¼δƥ���(���±꣬��һ��������¼��һ��)���±꣬��Ϊ�ָ���

int longestValidParentheses(std::string s)
{
	std::stack<int> left;
	int result = 0, last = -1;//last��¼��һ��)���±꣬�����ָ������ָ���Ч���ֶ�
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			left.push(i);
		else
		{
			if (left.empty())//��ߵ�(���Ѿ��õ�ƥ�䣬��ʱ��)������һ����Ч�ֶν���
				last = i;
			else
			{
				left.pop();//ƥ��һ��
				if (left.empty())//���������)()()
					result = std::max(result, i - last);
				else//���������(()()
					result = std::max(result, i - left.top());
			}
		}
	}
	return result;
}
