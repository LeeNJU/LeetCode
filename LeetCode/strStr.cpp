#include<iostream>
//��Ŀ������ʵ��strStr�����ַ���haystack���ҵ��ַ���needle��һ�γ��ֵ�λ�ã������±�
//�ⷨ�������ⷨ��
int strStr(char *haystack, char *needle)
{
	if (!*needle)//�ж�needle�Ƿ�Ϊ�մ������ǣ�ֱ�ӷ���0
		return 0;

	int lengthA = strlen(haystack), lengthB = strlen(needle);
	for (int i = 0; i <= lengthA - lengthB; ++i)//ע����С�ڵ��ں�,�����ַ���haystack
	{
		if (haystack[i] == needle[0])//�����һ���ַ���ȣ���ѭ���ж��Ƿ����
		{
			int index = i, j = 0;
			for (; index < lengthA && j < lengthB; ++index, ++j)
			{
				if (haystack[index] != needle[j])
					break;
			}
			if (j == lengthB)//�ж��Ƿ�����ȷ��
				return i;
		}
	}
	return -1;
}