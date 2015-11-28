#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
//题目描述:给定一个字符串，包含()和字母，去除字符串中的非法括号，使得整个字符串中的括号能够相互匹配，例如"()())()",去掉括号， 
//        得到["()()()", "(())()"]，要求去掉的括号最少，返回所有可能的结果
//解法描述:广度搜索，对每一个(或者)，去掉该括号，然后判断剩下的字符串是否合法，先只去掉一个括号，如果没有合法字符串，然后去掉2个
//        括号。
bool isValid(const std::string& s)//判断字符串的所有括号是否匹配
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
	std::queue<std::string> candidate;//保存所有可能的字符串
	candidate.push(s);
	std::unordered_set<std::string> visited;//保存已经访问过的字符串
	bool found = false;
	while (!candidate.empty())
	{
		std::string str = candidate.front();
		candidate.pop();
		if (isValid(str))//有效字符串，加入结果集中，并且表明found为true
		{
			found = true;
			result.push_back(str);
		}

		if (!found)//没有找到合法字符串，队列中的字符串继续去除括号
		{
			for (int i = 0; i < str.length(); ++i)
			{
				if (isalpha(str[i]))
					continue;

				std::string st = str.substr(0, i) + str.substr(i + 1);//去掉该括号
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