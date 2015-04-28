#include<vector>
#include<string>
#include<unordered_map>
//��Ŀ����������һ���ַ���s��word list��word����ͬ���ĳ��ȣ�����������leetcode��վ��
//�ⷨ��������һ��map����ÿ��word�Ĵ�����Ȼ������⣬����forѭ����

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
	int wordLength = words[0].length();
	int catLength = wordLength * words.size();
	std::vector<int> result;
	
	if (s.length() < catLength) //�������
		return result;

	std::unordered_map<std::string, int> wordCount;//����ÿ��word���ֵĴ���
	for (int i = 0; i < words.size(); ++i)
		++wordCount[words[i]];

	for (int i = 0; i <= s.length() - catLength; ++i) 
	{
		std::unordered_map<std::string, int> unused(wordCount);
		for (int j = i; j < i + catLength; j += wordLength) 
		{
			std::unordered_map<std::string, int>::iterator pos = unused.find(s.substr(j, wordLength));//��ȡһ��word�������Ƿ������wordlist��
			if (pos == unused.end() || pos->second == 0) //�����ھ�ֱ���˳�
				break;
			if (--pos->second == 0) //������ڣ��Ͱ�word�Ĵ�����ȥ1���������0����ɾ�����word
				unused.erase(pos);
		}
		if (unused.size() == 0) //����0��ʾÿ���ʶ�ֻ����һ��
			result.push_back(i);
	}
	return result;
}