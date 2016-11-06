#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

//��Ŀ����:����һ���ַ������飬�ҳ����е�anagrams,anagram��ָ�ַ������ַ����������һ����ֻ��˳��һ������
//        ����������{"aet", "tea","ate"}
//�ⷨ����:��ÿ���ַ������򣬰��������ַ�����Ϊmap��key�������ϣ���У�Ȼ����ĳһ��key��Ӧ���������ַ���
//        �ĸ����Ƿ����1

std::vector<std::string> anagrams(std::vector<std::string> &strs)
{
	std::vector<std::string> result;
	std::unordered_map<std::string, std::vector<std::string>> group;

	for (int i = 0; i < strs.size(); ++i)//��strs���ַ�����������Ȼ����Ϊkey���ѿ�����ȵ��ַ��������ϣ����
	{
		std::string key = strs[i];
		sort(key.begin(), key.end());
		group[key].push_back(strs[i]);
	}

	for (auto iter = group.begin(); iter != group.end(); ++iter)//ͬһ��key�����Ӧ���������1��˵���ж��anagram
	{
		if (iter->second.size() > 1)
			result.insert(result.end(), iter->second.begin(), iter->second.end());
	}

	return result;
}