#include<string>
//��Ŀ������ʵ��strStr�����ַ���haystack���ҵ��ַ���needle��һ�γ��ֵ�λ�ã������±�
//�ⷨ�������ⷨ��
int strStr(std::string haystack, std::string needle)
{
	if (needle.empty())//�ж�needle�Ƿ�Ϊ�մ������ǣ�ֱ�ӷ���0
		return 0;

	int lengthA = haystack.size(), lengthB = needle.size();
	for (int i = 0; i <= lengthA - lengthB; ++i)//ע����С�ڵ��ں�,�����ַ���haystack
	{
		if (haystack[i] == needle[0])
		{
			if (needle == haystack.substr(i, needle.size()))
				return i;
		}
	}
	return -1;
}