#include<string>
#include<cctype>
#include<iostream>
//��Ŀ����������һ���ַ���������ת����int
//Ҫ���Ⱥ��Կո��ҵ���һ���ǿո���ַ���Ҫ���ǵ�һ���ַ�������+����-��Ȼ������������֣�����Щ����ת����int��
//��Щ��Ч���ֺ���Ը������������ַ�������Ӱ��ֵ�����ֵԽ���ˣ�����INT_MAX����INT_MIN.����ǷǷ��ַ����򷵻�0
//�ⷨ�������Ⱥ���ǰ��Ŀհף�ֱ����һ���ǿ��ַ�����ȷ�����ţ�ʣ�µļ���

int myAtoi(std::string str)
{
	const int length = str.length();
	int i = 0, result = 0, sign = 1;
	while (isblank(str[i]) && i < length)//����ǰ��Ŀհ׷�
		++i;

	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;

	for (; i < length; ++i)
	{
		if (isdigit(str[i]))
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))//�ж��Ƿ�Խ�磬Ҫ�����ֵ����10���жϣ�ע���ʱresultֵΪ��
				return sign > 0 ? INT_MAX : INT_MIN;
			result = result * 10 + (str[i] - '0');

		}
		else
			break;
	}

	return  result * sign;
}
