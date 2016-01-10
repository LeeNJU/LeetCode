#include<unordered_map>
#include<vector>
//��Ŀ����:���������ַ������ж��������ַ����ǲ���ͬһ��ģʽ�����磺pattern = "abba", str = "dog cat cat dog" 
//         Ӧ�÷���true
//�ⷨ����:��hashtbale��ÿ��Ԫ�ض�Ӧ���±꣬Ȼ���ж϶�Ӧ���±��Ƿ����
bool wordPattern(std::string pattern, std::string str) 
{
	std::unordered_map<char, std::vector<int>> p;
	std::unordered_map<std::string, std::vector<int>> s;
	std::vector<std::string> st; //����str�����word�������������Ѱ��ÿ��word��patter�ַ������Ӧ���ַ�
	for (int i = 0; i < pattern.size(); ++i)//��hashtable����ÿ��Ԫ�ض�Ӧ���±�
		p[pattern[i]].push_back(i);

	std::string word;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] != ' ')
			word += str[i];
		else
		{
			st.push_back(word);
			s[word].push_back(st.size() - 1);
			word = "";
		}
	}

	if (word != "")//ע������
	{
		st.push_back(word);
		s[word].push_back(st.size() - 1);
	}

	if (st.size() != pattern.size())//��С�����һ��
		return false;

	for (int i = 0; i < st.size(); ++i)//����ÿһ��word���ҵ���Ӧ���ַ��������Ƚ����Ӧ���±��Ƿ�һ��
	{
		char corresponding = pattern[i];
		if (p[corresponding] != s[st[i]])
			return false;
	}
	return true;
}


//version 2
//��Ŀ����:s�ַ��������ÿո������Ȼ���ж�pattern��s�ǲ���ͬһ��ģʽ���ܲ��ܽ���ƥ��
//�ⷨ����:���ݷ����������
bool dfs(const std::string& pattern, int pindex, const std::string& s, int sindex, std::unordered_map<char, std::string>& m)
{
	if (pindex == pattern.size())
		return sindex == s.size();

	if (sindex == s.size())
		return false;

	if (m.find(pattern[pindex]) != m.end())//��ǰҪƥ����ַ�֮ǰ�Ѿ����ֹ�������֮ǰ��Ӧ���ַ����Ƚ�
	{
		std::string str = m[pattern[pindex]];
		if (str.size() > s.size() - sindex || s.substr(sindex, str.size()) != str)
			return false;
		return dfs(pattern, pindex + 1, s, sindex + str.size(), m);
	}
	else//��ǰ���ַ���֮ǰû�г��ֹ�
	{
		for (int i = sindex; i < s.size(); ++i)
		{
			std::string sub = s.substr(sindex, i - sindex + 1);
			bool exist = false;
			auto iter = m.begin();
			while (iter != m.end())//�����ж��ַ���sub�ǲ�����֮ǰ��ƥ���
			{
				if (iter->second == sub)
				{
					exist = true;
					break;
				}
			}

			if (exist)//֮ǰ��ƥ���
				continue;

			m[pattern[pindex]] = sub;
			if (dfs(pattern, pindex + 1, s, i + 1, m))
				return true;
			m.erase(pattern[pindex]);
		}
	}
	return false;
}

bool wordPatternMatch(std::string pattern, std::string str)
{
	std::unordered_map<char, std::string> mp;
	return dfs(pattern, 0, str, 0, mp);
}