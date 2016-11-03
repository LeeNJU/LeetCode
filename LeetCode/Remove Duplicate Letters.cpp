#include<vector>
#include<string>
#include<stack>
//题目描述:给定一个字符串，要求去除所有重复元素，使得每个元素只出现一次，并且最后的结果是字典序中最小的，例如
//        "bcabc"得到"abc"
//解法描述:用一个栈保存当前的最优解，如果当前元素比栈顶元素小，并且栈顶元素并不是最后一次出现，并且当前元素不在
//        栈中，那么弹出栈顶元素，加入当前元素
std::string removeDuplicateLetters(std::string s) 
{
	std::vector<bool> exist(26, false);//在栈中是否出现
	std::vector<int> vec(26, 0); //统计每个字符的次数和已经出现的次数
	for (int i = 0; i < s.length(); ++i)
		++vec[s[i] - 'a'];

	std::stack<char> stack;//栈保存当前的最优解
	for (int i = 0; i < s.length(); ++i)
	{
		while (!stack.empty() && stack.top() > s[i] && vec[stack.top() - 'a']
			&& !exist[s[i] - 'a'])//当前字符比栈顶字符要小，并且栈顶字符并不是最后一次出现，并且当前字符不在栈中
		{
			exist[stack.top() - 'a'] = false;
			stack.pop();
		}

		if (!exist[s[i] - 'a'])
		{
			stack.push(s[i]);
			exist[s[i] - 'a'] = true;
		}
		--vec[s[i] - 'a'];
	}

	std::string result;
	while (!stack.empty())//取出栈中元素再反转
	{
		result += stack.top();
		stack.pop();
	}
	std::reverse(result.begin(), result.end());
	return result;
}