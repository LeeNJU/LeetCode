#include<string>
#include<vector>
//��Ŀ����:����һ���ַ������жϸ��ַ�����ĳ������ܲ������һ�����Ĵ�������"aab"�������"aba"
//�ⷨ����:����ܹ���ɻ��Ĵ�����ô�ַ����ֵĴ���Ϊż�������ֻ����һ���ַ��ĳ��ִ���Ϊ����
bool canPermutePalindrome(std::string s)
{
	int dict[256] = { 0 };
	std::vector<int> vec(256, 0);
	for (int i = 0; i < s.size(); ++i)//ͳ��ÿ���ַ��Ĵ���
		++vec[s[i]];

	int count = 0;
	for (int i = 0; i<256; i++)//ͳ�������ַ��ĸ���
	{
		if (vec[i] % 2 != 0)   
			++count;
	}

	return count <= 1;
}