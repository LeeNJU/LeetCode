#include<string>
#include<vector>
#include<algorithm>
//��Ŀ����:����һ���ַ�����k�������������ַ��滻�ַ����е��ַ�������滻k�Σ�ʹ���滻֮����ַ����д������ַ�
//        �������ַ������ַ�����ͬ�����������ַ�������󳤶ȣ�����"AABABBA", k = 1�����м��A����B���õ�
//        "AABBBBA",�������ַ�����"BBBB"������4
//�ⷨ����:�������ڣ���¼���������г��ִ��������ַ������max_count����k���ڻ������ڵĴ�С��˵������ͨ��k��
//        �����ѻ��������е��ַ��������ͬ���ַ������max_count����kС�ڻ������ڵĴ�С����������ƶ���������

int characterReplacement(std::string s, int k) 
{
	std::vector<int> charCount(26, 0);
	int start = 0, max_count = 0;

	for (int end = 0; end < s.size(); ++end)
	{
		++charCount[s[end] - 'A'];
		max_count = std::max(max_count, charCount[s[end] - 'A']);
		if (max_count + k < end - start + 1)//����ͨ��k�β����ѻ��������е�Ԫ�ر����ͬ�ַ�
		{
			--charCount[s[start] - 'A'];
			++start;
		}
	}
	return s.size() - start;
}