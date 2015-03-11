#include<string>
#include<vector>
//��Ŀ����������һ���ַ�����ʾip��ַ���������иõ�ַ���ܱ�ʾ��ip��ַ��"25525511135"��ʾΪ"255.255.11.135", "255.255.111.35"
//

void dfs(std::vector<std::string>& result, std::string ip, const std::string& s, int index, int step)//step��ʾ�ݹ���ȣ�index��ʾ��s���￪ʼ
{
	if (index == s.size() && step == 4)
	{
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}


	int num = 0;
	for (int i = index; i < index + 3 && i < s.size(); ++i)//ÿ�����ֻ�����3��Ԫ�أ���Ϊip���ֶγ���Ϊ3
	{
		num = num * 10 + s[i] - '0';
		if (num <= 255)//��ǰ�ڵ�Ϸ��������ݹ�
		{
			ip += s[i];
			dfs(result, ip + '.', s, i + 1, step + 1);
		}
		if (num == 0)//ÿ���ֶε�ǰ׺������0���������������ֶ���0��������0�����
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

