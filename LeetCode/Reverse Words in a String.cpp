#include<string>
//��Ŀ����:����һ���ַ���������������ʣ�ÿ��������һ�������ո��������ͷ�ͽ�β�����пո�Ҫ��Է�ת�ַ�����
//        ���һ�����ʷ��ڵ�һ��λ�ã������ڶ������ʷ��ڵڶ���λ�ã�ÿ��������һ���ո��������ͷ�ͽ�β������
//        �ո�
//�ⷨ����:�Ӻ���ǰɨ��
void reverseWords(std::string& s)
{
	std::string result;
	for (int i = s.size() - 1; i >= 0;)
	{
		while (i >= 0 && isspace(s[i]))//ȥ��ÿ������ǰ��Ŀո�
			--i;

		if (i < 0)//û�е�����
			break;

		int j = i;
		while (i >= 0 && !isspace(s[i]))
			--i;

		result += s.substr(i + 1, j - i) + ' ';
	}
	s = result.substr(0, result.size() - 1);
}

//version 2
//�����ַ�����ͷ�ͽ�βû�пո�ÿ������ֻ��һ���ո������Ҫ��ͬ��
//�ⷨ����:�������ַ�����תһ�飬Ȼ���ÿ�������ٷ�תһ��
void reverse(std::string& s, int left, int right) 
{
	while (left < right)
		std::swap(s[left++], s[right--]);
}

void reverseWords2(std::string& s) 
{
	reverse(s, 0, s.size() - 1);//��ת�����ַ���

	int first = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (isspace(s[i]))//�ҵ�һ������
		{
			reverse(s, first, i - 1);
			first = i + 1;
		}
	}
	reverse(s, first, s.size() - 1);//��ת��β�ĵ���
}