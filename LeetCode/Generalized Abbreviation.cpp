#include<string>
#include<vector>
//��Ŀ����:�����ַ�����������п��ܵ���д���������"word",��ô���ܵ���д�����["word", "1ord", "w1rd", "wo1d", "wor1",
//        "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//�ⷨ����:�ݹ���٣�ÿһ���ַ������ֿ��ܣ�������д�Ͳ�������д�����������д����Ҫ��������������
void dfs(std::string& word, std::string t, int i, std::vector<std::string>& result, bool prevNum)
{                         //prevNum��ʾ��һ���Ƿ��������
	if (i == word.length())
	{
		result.push_back(t);
		return;
	}

	dfs(word, t + word[i], i + 1, result, false);//��������д
	if (!prevNum)//��һ��û���������
	{
		for (int len = 1; i + len <= word.length(); ++len) 
			dfs(word, t + std::to_string(len), i + len, result, true);
	}
}

std::vector<std::string> generateAbbreviations(std::string word) 
{
	std::vector<std::string> result;
	dfs(word, "", 0, result, false);
	return result;
}