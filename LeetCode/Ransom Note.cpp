#include<vector>
#include<string>
//��Ŀ����:���������ַ������жϵ�һ���ַ����ܲ����ɵڶ����ַ����е��ַ����ɣ�����"aa", "aab",����true
//�ⷨ����:��¼�ڶ����ַ����ĸ������жϵ�һ���ַ����е��ַ����ִ����ǲ���С�ڵ��ڵڶ���

bool canConstruct(std::string ransomNote, std::string magazine) 
{
	std::vector<int> mag(256, 0);
	for (int i = 0; i < magazine.size(); ++i)
		++mag[magazine[i]];

	for (int i = 0; i < ransomNote.size(); ++i)
	{
		if (mag[ransomNote[i]] == 0)
			return false;

		--mag[ransomNote[i]];
	}
	return true;
}