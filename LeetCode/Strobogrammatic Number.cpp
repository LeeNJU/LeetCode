#include<string>
#include<unordered_map>
//��Ŀ����:����һ���ַ������֣������Щ���ַ�ת180�ȣ��ж��Ƿ��ԭ���������ַ�����ȣ�����"69",��ת180�Ⱥ󣬻���"69"
//�ⷨ����:����ָ�����м��ߣ����߷�ת֮��������
bool isStrobogrammatic(std::string num) 
{
	std::unordered_map<char, char> m;
	m['0'] = '0';//ֻ����Щ�ַ���ת180�Ⱥ���һ������
	m['1'] = '1';
	m['6'] = '9';
	m['8'] = '8';
	m['9'] = '6';

	for (int i = 0, j = num.length() - 1; i <= j; ++i, --j)
	{
		if (m.find(num[i]) == m.end() || m[num[i]] != num[j])//�����ǰ�ַ�����map����������Ҳ���
			return false;
	}
	return true;
}