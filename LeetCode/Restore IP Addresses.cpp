#include<string>
#include<vector>
//题目描述：给定一个字符串表示ip地址，返回所有该地址所能表示的ip地址，"25525511135"表示为"255.255.11.135", "255.255.111.35"
//解法描述：递归回溯，但是要注意某个字段为0的情况

void dfs(std::vector<std::string>& result, std::string ip, const std::string& s, int index, int step)//step表示递归深度，index表示从s哪里开始
{
	if (step == 4)
	{
		if (index == s.size())
		{
			ip.resize(ip.size() - 1);
			result.push_back(ip);
		}
		return;
	}


	for (int i = index; i < index + 3 && i < s.size(); ++i)//每次最多只能向后看3个元素，因为ip的字段长度为3
	{
		int num = std::stoi(s.substr(index, i - index + 1)); //转换成整数
		if (num <= 255)  //值必须小于255
			dfs(result, ip + std::to_string(num) + ".", s, i + 1, step + 1);

		if (num == 0) //不允许前缀为0，但是允许单个的0
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

