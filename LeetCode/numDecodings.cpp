#include<string>
#include<vector>
//��Ŀ�������������¹���A->1, B->2,...,Z->26,ÿ����ĸ��Ӧһ�����֣��ָ���һ�������ַ��������䷭�����ĸ�����ܹ��ж��ٵĽ��뷽��  "12"���Է���ΪAB����L
//�ⷨ��������̬�滮
//bugs
int numDecodings(std::string s)//�ܵ�˼·���������飬ͳ����һ�Ե����
{
	if (s.empty() || s[0] == '0')
		return 0;

	std::vector<int> result(s.length() + 2, 0);
	std::string temp = "00" + s;
	result[0] = 0, result[1] = 1;

	for (int i = 2; i < temp.length(); ++i)
	{
		if (temp[i] == '0' && stoi(temp.substr(i - 1, 2)) <= 26)
			result[i] = result[i - 2];
		else if (temp[i] != '0' && stoi(temp.substr(i - 1, 2)) <= 26)
			result[i] = result[i - 1] + result[i - 2];
		else
			result[i] = result[i - 1];
	}
	return result [result.size() - 1];
}

