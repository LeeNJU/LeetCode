#include<string>
//��Ŀ����������һ��������ַ������һ���ַ������������ҵ���һ���ϸ��������ַ����ַ�����������в���������ַ�������
//         �����е���СԪ��
//�ⷨ���������ֲ��ң����s[middle]��a����ô��¼result��Ȼ��������ֲ���

char smallestCharacter(std::string& s, char a)
{
	int left = 0, right = s.size() - 1, middle = 0;
	char result = s[0];
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (s[middle] > s[a])
		{
			result = s[middle];
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return result;
}