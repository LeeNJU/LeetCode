#include<string>
//��Ŀ����:����һ���ַ�����ʾlicense key���м���-�ָ������ַ������и�ʽ����ʹ��ÿһ���ֶ�����K���ַ���ÿһ����
//        ��-�ָ�������S = "2-4A0r7-4k", K = 4�����¸�ʽ��֮��Ϊ"24A0-R74K"����һ���ֲ�һ������K���ַ�
//�ⷨ����:����ɨ�裬����-����¼ÿһ���ֵ��ַ�����������K��ʱ�����-

std::string licenseKeyFormatting(std::string S, int K) 
{
	std::string result;
	int count = 0;
	for (int i = S.size() - 1; i >= 0; --i)
	{
		if (S[i] == '-')
			continue;

		if (count == K)
		{
			result = "-" + result;
			count = 0;
		}

		S[i] = toupper(S[i]);
		result = S[i] + result;
		++count;
	}
	return result;
}