#include<string>
#include<vector>
//题目描述：给定一个字符串表示ip地址，返回所有该地址所能表示的ip地址，"25525511135"表示为"255.255.11.135", "255.255.111.35"
//

void dfs(std::vector<std::string>& result, std::string ip, const std::string& s, int index, int step)//step表示递归深度，index表示从s哪里开始
{
	if (index == s.size() && step == 4)
	{
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}


	int num = 0;
	for (int i = index; i < index + 3 && i < s.size(); ++i)//每次最多只能向后看3个元素，因为ip的字段长度为3
	{
		num = num * 10 + s[i] - '0';
		if (num <= 255)//当前节点合法，继续递归
		{
			ip += s[i];
			dfs(result, ip + '.', s, i + 1, step + 1);
		}
		if (num == 0)//每个字段的前缀不能是0，但是允许整个字段是0，即单个0的情况
			break;
	}
}

std::vector<std::string> restoreIpAddresses(std::string s)
{
	std::vector<std::string> result;
	std::string ip;
	dfs(result, ip, s, 0, 0);
	return result;
}

