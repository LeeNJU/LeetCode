#include<string>
#include<unordered_map>
//��Ŀ����:����һ�����֣����16������ʽ���������26������"1a",����-1������"ffffffff"
//�ⷨ����:�ù�ϣ����ÿ�����ֶ�Ӧ��16������ʽ�����ڸ��������֣�ÿ�ο����ұߵ�4λ���ҵ���Ӧ��16������ʽ��
//        Ȼ�������ƶ�4λ

std::string toHex(int num) 
{
	std::unordered_map<int, char> map;
	for (int i = 0; i < 10; ++i)
		map[i] = i + '0';

	map[10] = 'a';
	map[11] = 'b';
	map[12] = 'c';
	map[13] = 'd';
	map[14] = 'e';
	map[15] = 'f';

	int mask = 15;
	std::string s = "";
	for (int i = 0; i < 8; ++i)
	{
		int val = num & mask;
		s = map[val] + s;
		num = num >> 4;
	}

	int index = 0;
	while (index < s.size() - 1 && s[index] == '0')//ȥ��ǰ���0
		++index;

	return s.substr(index);
}