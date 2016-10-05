#include<vector>
#include<string>

//��Ŀ����:����һ���ַ��������һ����󳤶�maxWidth�����и�ʽ����ʹ��ÿһ���ַ��������ܶ�İ����ַ���������
//         ���ַ��������ҳ��Ȳ��ܳ�����󳤶�
//�ⷨ����:ע������ַ����ĳ��ȣ�������ȳ�����󳤶ȣ�����ӿո��γ�һ���ϸ���ַ��������뵽result��

void addSpaces(std::string &s, int i, int n, int L, bool is_last) 
{
	if (n < 1 || i > n - 1) 
		return;
	int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
	s.append(spaces, ' ');
}

std::string connect(const std::vector<std::string> &words, int begin, int end, int len, int maxWidth, bool is_last) //����begin��end��λ��
{                                                                                                        //����һ�кϸ���ַ���
	std::string s;
	int n = end - begin + 1;
	for (int i = 0; i < n; ++i) //�����������������ӿո�
	{
		s += words[begin + i];
		addSpaces(s, i, n - 1, maxWidth - len, is_last);
	}
	if (s.size() < maxWidth)  //����ĩβ�Ŀո�
		s.append(maxWidth - s.size(), ' ');
	return s;
}

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth)
{
	std::vector<std::string> result;
	const int n = words.size();
	int begin = 0, len = 0; // ��ǰ�е���㣬��ǰ����
	for (int i = 0; i < n; ++i) 
	{
		if (len + words[i].size() + (i - begin) > maxWidth) //�ַ������ȼӿո���������������󳤶� 
		{
			result.push_back(connect(words, begin, i - 1, len, maxWidth, false));
			begin = i;
			len = 0;
		}
		len += words[i].size();  //�����ַ����ĳ����ۼ�
	}
	// ���һ�в���L
	result.push_back(connect(words, begin, n - 1, len, maxWidth, true));
	return result;
}