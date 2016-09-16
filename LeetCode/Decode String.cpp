#include<string>
#include<stack>
//题目描述:对字符串进行解码，字符串的格式为k[encoded_string]，k是数字，括号内的字符串不包括数字，例如
//        "2[abc]3[cd]ef",解码之后是"abcabccdcdcdef"，"3[a2[c]]"解码之后是"accaccacc"，括号可以嵌套。
//解法描述:用两个栈，数字栈保存前面的数字，字符串栈保存括号之间的字符串，数字入栈，左括号入栈，当碰到右括号，
//        取出字符串栈中的字符串进行拼接，直到碰到左括号，然后重复一定次数，再压入字符串栈。

std::string decodeString(std::string s)
{
	std::stack<int> num;
	std::stack<std::string> stack;
	std::string result = "";

	for (int i = 0; i < s.size();)
	{
		if (isdigit(s[i]))//取出数字，放入数字栈中
		{
			int index = i;
			while (isdigit(s[index]))
				++index;

			num.push(stoi(s.substr(i, index - i)));
			i = index;
		}
		else if (s[i] == '[')//左括号入栈
		{
			stack.push("[");
			++i;
		}
		else if (isalpha(s[i]))//找到当前字符串，并放入字符串栈
		{
			int index = i;
			while (index < s.size() && isalpha(s[index]))
				++index;

			stack.push(s.substr(i, index - i));
			i = index;
		}
		else//碰到右括号
		{
			std::string str = "";
			while (stack.top() != "[")//把当前括号内的字符串合并成一个字符串
			{
				str = stack.top() + str;
				stack.pop();
			}
			stack.pop();

			int val = num.top();
			num.pop();
			std::string temp = "";
			while (val > 0)//取出数字栈中的数字，重复字符串
			{
				--val;
				temp += str;
			}

			stack.push(temp);//得到的字符串压入栈中
			++i;
		}
	}

	while (!stack.empty() && stack.top() != "[")//把字符串栈中的字符串拼接起来
	{
		result = stack.top() + result;
		stack.pop();
	}

	return result;
}