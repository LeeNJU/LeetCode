//��Ŀ������ƥ���ַ���������ʾƥ���κε�һ���ַ���*��ʾƥ���������е��ַ�
//�ⷨ��������ǰ�������ɨ�裬������*ʱ����һ��������¼�Ƿ�����*��
bool isMatch(const char *s, const char *p)
{
	bool star = false;
	const char* str, *ptr;
	for (str = s, ptr = p; *str != '\0'; ++str, ++ptr)//ѭ����������ֻ��Ҫ�ж�str�Ƿ�Ϊ�վͿ����ˣ���Ϊ��ʹ*ptrΪ�գ���default�Ӿ��У�ptr��������ƶ�������str������ƶ���ֱ��*strΪ��
	{
		switch (*ptr)
		{
		case '?':
			break;
		case '*'://����*��star��Ϊtrue�������������ֵ�*��str���䣬ptr�ƶ�һλ
			star = true;
			s = str, p = ptr;
			while (*p == '*')//�����������ֵ�*
				++p;
			if (*p == '\0')
				return true;
			str = s - 1;
			ptr = p - 1;
			break;
		default:
			if (*str != *ptr)//����Ԫ�ز���ʱ�������������ǰ���Ѿ�����*��ʱ��ptrָ�벻����strָ����ǰ�ƶ�һλ����ǰ��û������*��ʱ����ʾ��ƥ��
			{
				if (!star)//û������*��˵����ƥ��
					return false;
				++s;//str�ƶ�һλ��ptr����
				str = s - 1;
				ptr = p - 1;
			}
		}
	}

	while (*ptr == '*')
		++ptr;

	return *ptr == '\0';

}


//�汾��
//��Ŀ������ƥ���ַ���.��*��.��ʾ���ⵥһ�ַ���*��ʾǰһ���ַ�����0�λ���
//�ⷨ������ע����ƥ��ĳһ���ַ�ʱ��Ҫ����һ���ַ��Ƿ���*

bool isMatchs(const char* s, const char* p)
{
	if (*p == '\0')
		return *s == '\0';

	if (*(p + 1) != '*')//��һ���ַ�����*
	{
		if (*p == *s || *p == '.' && *s != '\0')//ƥ��ɹ����͵ݹ�ƥ����һ���ַ�
			return isMatchs(s + 1, p + 1);
		else
			return false;
	}
	else
	{
		while (*p == *s || *p == '.' && *s != '\0')
		{
			if (isMatchs(s, p + 2))
				return true;
			++s;
		}
		return isMatchs(s, p + 2);
	}
}