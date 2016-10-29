#include<vector>
#include<string>
#include<unordered_map>
//��Ŀ����:���������ַ���s��p����s���ҵ����е����ַ�������ʼ�±꣬ʹ�����ַ�����p��anagram����������ַ���
//        s = "cbaebabacd", p = "abc",����[0,6]
//�ⷨ����:hashtable��sliding window��count��ʾ��ǰsliding window�г����˶��ٸ�p�е��ַ������sliding 
//        window�ĳ��ȵ���p�ĳ��Ȳ���count����0��˵���ҵ�һ��anagram��

std::vector<int> findAnagrams(std::string s, std::string p) 
{
	std::vector<int> result;
	std::unordered_map<char, int> map;
	for (char c : p)
		++map[c];

	int count = p.size();
	for (int i = 0, j = 0; j < s.size(); ++j)
	{
		if (map.find(s[j]) != map.end() && --map[s[j]] >= 0)//ע���������count������
			--count;

		if (j - i + 1 == p.size())
		{
			if (count == 0)
				result.push_back(i);
			if (map.find(s[i]) != map.end() && ++map[s[i]] >= 1)//����count������
				++count;
			++i;
		}
	}

	return result;
}