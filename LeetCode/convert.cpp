#include<string>

//��Ŀ�����������ַ���PAYPALISHIRING�������·�ʽ�����
//P   A   H   N
//A P L S I I G
//Y   I   R, ת����PAHNAPLSIIGYIR����һ����������
//�ⷨ������A��L�ľ����ǹ̶��ģ�����A��P�ľ���2 * (n - 1 - i)������P��L�ľ���2 * i

std::string converts(std::string s, int numRows) {
	if (numRows <= 1)
		return s;

	std::string str = "";
	int index = 0;
	for (int i = 0; i < numRows && i < s.size(); ++i)
	{
		index = i;
		str += s[index];
		while (index < s.size())
		{
			index += (numRows - 1 - i) * 2;
			if ((numRows - 1 - i) * 2 != 0 && index < s.size())
				str += s[index];
			index += 2 * i;
			if (2 * i != 0 && index < s.size())
				str += s[index];
		}
	}
	return str;
}