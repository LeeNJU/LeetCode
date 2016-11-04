#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
//��Ŀ����:����һ���ַ���������()����ĸ��ȥ���ַ����еķǷ����ţ�ʹ�������ַ����е������ܹ��໥ƥ�䣬����
//        "()())()",ȥ������,�õ�["()()()", "(())()"]��Ҫ��ȥ�����������٣��������п��ܵĽ��
//�ⷨ����:�����������ÿһ��(����)��ȥ�������ţ�Ȼ���ж�ʣ�µ��ַ����Ƿ�Ϸ�����ֻȥ��һ�����ţ����û�к�
//        ���ַ�����Ȼ��ȥ��2�����š�
bool isValid(const std::string& s)//�ж��ַ��������������Ƿ�ƥ��
{
	std::stack<char> stack;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
			stack.push(s[i]);
		else if (s[i] == ')')
		{
			if (stack.empty() || stack.top() != '(')
				return false;
			stack.pop();
		}
	}
	return stack.empty();
}

std::vector<std::string> removeInvalidParentheses(std::string s) 
{
	std::vector<std::string> result;
	std::queue<std::string> candidate;//�������п��ܵ��ַ���
	candidate.push(s);
	std::unordered_set<std::string> visited;//�����Ѿ����ʹ����ַ���
	bool found = false;
	while (!candidate.empty())
	{
		std::string str = candidate.front();
		candidate.pop();
		if (isValid(str))//��Ч�ַ��������������У����ұ���foundΪtrue
		{
			found = true;
			result.push_back(str);
		}

		if (!found)//û���ҵ��Ϸ��ַ����������е��ַ�������ȥ������
		{
			for (int i = 0; i < str.length(); ++i)
			{
				if (isalpha(str[i]))
					continue;

				std::string st = str.substr(0, i) + str.substr(i + 1);//ȥ��������
				if (visited.find(st) == visited.end())
				{
					candidate.push(st);
					visited.insert(st);
				}
			}
		}
	}

	return result;
}