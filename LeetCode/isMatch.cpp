//题目描述：匹配字符串，？表示匹配任何单一的字符，*表示匹配任意序列的字符
//解法描述：从前往后逐个扫描，当碰到*时，用一个变量记录是否遇到*号
bool isMatch(const char *s, const char *p)
{
	bool star = false;
	const char* str, *ptr;
	for (str = s, ptr = p; *str != '\0'; ++str, ++ptr)//循环结束条件只需要判断str是否为空就可以了，因为即使*ptr为空，在default子句中，ptr不会向后移动，反而str会继续移动，直到*str为空
	{
		switch (*ptr)
		{
		case '?':
			break;
		case '*'://遇到*，star设为true，忽略连续出现的*，str不变，ptr移动一位
			star = true;
			s = str, p = ptr;
			while (*p == '*')//忽略连续出现的*
				++p;
			if (*p == '\0')
				return true;
			str = s - 1;
			ptr = p - 1;
			break;
		default:
			if (*str != *ptr)//两个元素不等时，分两种情况，前面已经遇到*号时，ptr指针不动，str指针向前移动一位，当前面没有遇到*号时，表示不匹配
			{
				if (!star)//没有遇到*，说明不匹配
					return false;
				++s;//str移动一位，ptr不变
				str = s - 1;
				ptr = p - 1;
			}
		}
	}

	while (*ptr == '*')
		++ptr;

	return *ptr == '\0';

}