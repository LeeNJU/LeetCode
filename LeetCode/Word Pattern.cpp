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