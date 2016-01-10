#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
//��Ŀ����:����һ��ѹ����ʽ���ַ�����ѹ����<��һ���ַ�><�м��ַ����ĳ���><���һ���ַ�>���ָ�ʽ�����ڸ���һ��dictionary��
//        ��һ���ַ������жϸ��ַ�����ѹ������ǲ���Ψһ�ģ���dictionary�е��ַ���ѹ���������֮��ͬ
//�ⷨ����:��map����ѹ������Ͷ�Ӧ���ַ���

class ValidWordAbbr 
{
private:
	std::unordered_map<std::string, std::unordered_set<std::string>> mp;

public:
	ValidWordAbbr(std::vector<std::string>& dictionary) 
	{
		for (std::string& d : dictionary) 
		{
			int n = d.length();
			std::string abbr = d[0] + std::to_string(n - 2) + d[n - 1];
			mp[abbr].insert(d);
		}
	}

	bool isUnique(std::string word) 
	{
		int n = word.length();
		std::string abbr = word[0] + std::to_string(n - 2) + word[n - 1];
		return mp[abbr].count(word) == mp[abbr].size();
	}
};