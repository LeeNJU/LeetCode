#include<string>
#include<vector>
//��Ŀ����:����һ���ַ���ֻ����+��-�����ڰ�����������++�������������--��������õ������ֽ��
//�ⷨ����:ɨ��һ��
std::vector<std::string> generatePossibleNextMoves(std::string s) 
{
	std::vector<std::string> moves;
	for (int i = 0; i < s.size() - 1; ++i) 
	{
		if (s[i] == '+' && s[i + 1] == '+') 
		{
			s[i] = s[i + 1] = '-';
			moves.push_back(s);
			s[i] = s[i + 1] = '+';
		}
	}
	return moves;
}

//version 2
//��Ŀ����:����һ���ַ���ֻ����+��-��������������������+���-�������任�����û��������++����ô���˻�ʤ��
//        �жϸ����Ƿ��ʤ
//�ⷨ����:�ݹ飬�������еĽ�
bool canWin(std::string s) 
{
	for (int i = -1; (i = s.find("++", i + 1)) >= 0;)//�ҵ�һ��������++
	{
		if (!canWin(s.substr(0, i) + '-' + s.substr(i + 2)))//��������++���-��Ȼ��ݹ��ж�
			return true;
	}
	return false;
}