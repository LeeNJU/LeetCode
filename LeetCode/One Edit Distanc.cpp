#include<string>
//��Ŀ����:���������ַ������ж��������ַ����ı༭�����ǲ���1
//�ⷨ����:���ȳ��Ȳ�ܳ���1�����������ͬ�����ֻ����һ����ͬ���ַ���������Ȳ�Ϊ1�������һ���ַ���ͬ,����
//        �ַ�����һ��
bool isOneDifL(std::string s, std::string t)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == t[i])
			continue;
		return s.substr(i) == t.substr(i + 1);
	}
	return true; // ˵��ǰ��Ķ����ֻ�����һ����ƥ��
}
bool isSameLen(std::string s, std::string t)//������ȣ������һ����ͬ���ַ�
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
			++count;
	}
	return count == 1;
}
bool isOneEditDistance(std::string s, std::string t)
{
	if (std::abs(s.length - t.length) > 1) //���Ȳ��1
		return false;
	if (s.size() == t.size()) //������ȣ������һ����ͬ���ַ�
		return isSameLen(s, t);
	else if (s.size() < t.size()) //�������1����ô�����ַ����ȶ̵��ַ�����һ���ַ���������ַ�������ͬ
		return isOneDifL(s, t);
	else return isOneDifL(t, s);
}