#include<string>
#include<vector>
//��Ŀ����������һ���ַ�����ʾip��ַ���������иõ�ַ���ܱ�ʾ��ip��ַ��"25525511135"��ʾΪ"255.255.11.135", "255.255.111.35"
//�ⷨ�������ݹ���ݣ�����Ҫע��ĳ���ֶ�Ϊ0�����

void dfs(std::vector<std::string>& result, std::string ip, const std::string& s, int index, int step)//step��ʾ�ݹ���ȣ�index��ʾ��s���￪ʼ
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


	for (int i = index; i < index + 3 && i < s.size(); ++i)//ÿ�����ֻ�����3��Ԫ�أ���Ϊip���ֶγ���Ϊ3
	{
		int num = std::stoi(s.substr(index, i - index + 1)); //ת��������
		if (num <= 255)  //ֵ����С��255
			dfs(result, ip + std::to_string(num) + ".", s, i + 1, step + 1);

		if (num == 0) //������ǰ׺Ϊ0��������������0
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

