#include<string>
#include<vector>
//��Ŀ����:����һ���ַ������жϸ��ַ�����ĳ������ܲ������һ�����Ĵ�������"aab"�������"aba"
//�ⷨ����:����ܹ���ɻ��Ĵ�����ô�ַ����ֵĴ���Ϊż�������ֻ����һ���ַ��ĳ��ִ���Ϊ����
bool canPermutePalindrome(std::string s)
{
	std::vector<int> vec(256, 0);
	for (int i = 0; i < s.size(); ++i)//ͳ��ÿ���ַ��Ĵ���
		++vec[s[i]];

	int count = 0;
	for (int i = 0; i < vec.size(); ++i)//ͳ�������ַ��ĸ���
	{
		if (vec[i] % 2 != 0)   
			++count;
	}

	return count <= 1;
}