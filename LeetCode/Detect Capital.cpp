#include<string>
#include<cctype>
//��Ŀ����:����һ���ַ������ж��ǲ��ǺϷ����ַ��������ȫ���Ǵ�д��ĸ������ȫ��Сд��ĸ�����ߵ�һ����ĸ�Ǵ�д��
//        ������ĸ��Сд�����ǺϷ����ַ���
//�ⷨ����:ͳ�ƴ�д��ĸ��Сд��ĸ�ĸ�����һ���ж�

bool detectCapitalUse(std::string word)
{
	int upper = 0, lower = 0;
	for (int i = 0; i < word.size(); ++i)
	{
		if (isupper(word[i]))
			++upper;
		else
			++lower;
	}

	return upper == word.size() || lower == word.size() || (upper == 1 && isupper(word[0]));
}