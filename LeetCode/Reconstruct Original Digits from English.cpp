#include<string>
#include<vector>
//��Ŀ����:����һ���ַ�����������0��9��Ӣ�ĵ�����ɣ������ַ�֮���˳�򱻴��ң�Ҫ�󷵻ض�Ӧ�������ַ���������
//        �����ַ���"owoztneoer"�����ַ�����ʾ"zereoonetwo",��ô�ͷ���"012"
//�ⷨ����:ÿ�����ֵ�Ӣ�ĵ��ʶ��ж��ص��ַ�������ֻ��zero����z��ֻ��two����w����һ�������ʾÿ�����ֳ��ֵ�
//        ����

std::string originalDigits(std::string s) 
{
	std::vector<int> count(10, 0);
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if (c == 'z') 
			++count[0];
		if (c == 'w') 
			++count[2];
		if (c == 'x') 
			++count[6];
		if (c == 's')//ע�����6��7������s 
			++count[7]; //7-6
		if (c == 'g') 
			++count[8];
		if (c == 'u') 
			++count[4];
		if (c == 'f') 
			++count[5]; //5-4
		if (c == 'h') 
			++count[3]; //3-8
		if (c == 'i') 
			++count[9]; //9-8-5-6
		if (c == 'o') 
			++count[1]; //1-0-2-4
	}

	count[7] -= count[6];//��ȥ6���ֵĴ����õ�7���ֵĴ���
	count[5] -= count[4];
	count[3] -= count[8];
	count[9] = count[9] - count[8] - count[5] - count[6];
	count[1] = count[1] - count[0] - count[2] - count[4];
	
	std::string result = "";
	for (int i = 0; i <= 9; i++)//ͳ��ÿ���ַ����ֵĴ���
	{
		for (int j = 0; j < count[i]; j++)
			result += std::to_string(i);
	}
	return result;
}