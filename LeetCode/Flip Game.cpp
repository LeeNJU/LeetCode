#include<string>
#include<vector>
//��Ŀ����:����һ���ַ���ֻ����+��0�����ڰ�����������++�������������--��������õ������ֽ��
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