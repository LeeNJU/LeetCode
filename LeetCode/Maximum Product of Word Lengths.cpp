#include<string>
#include<vector>
//��Ŀ����:����һ���ַ������飬�ҵ������ַ���ʹ�����ǳ��ȵĳ˻���󣬲����������ַ���֮��û�й����ַ�
//�ⷨ����:��ÿһ���ַ���ת����int���֣���Ϊֻ��26����ĸ��������intֵ���棬Ȼ���������������û�й����ַ���
//        ����������0
int maxProduct(std::vector<std::string>& words)
{
	std::vector<int> vec(words.size(), 0);
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words[i].length(); ++j)
			vec[i] |= (1 << (words[i][j] - 'a')); //ת����intֵ
	}


	int result = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = i + 1; j < words.size(); ++j)
		{
			if (!(vec[i] & vec[j]) && words[i].length() * words[j].length() > result)
				result = words[i].length() * words[j].length();
		}
	}
	return result;
}