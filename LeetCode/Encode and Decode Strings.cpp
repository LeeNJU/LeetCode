#include<string>
#include<vector>
//��Ŀ����:�ַ������ܺͽ��ܣ�����һ���ַ������飬���ַ��������һ���ַ�����Ȼ�������ַ�������õ�ԭ�����ַ�������
//�ⷨ����:��������������ַ����ĳ��ȣ�Ȼ����һ�������ַ���Ϊÿ���ַ�������ʼsentinel(�������sentinel,�޷��õ��ַ���
//         ���ȣ���Ϊ�ַ�����ͷ���ܱ���Ͱ�������)��Ȼ�����ַ���
class Codec 
{
public:
	std::string encode(std::vector<std::string>& strs) 
	{
		std::string s;
		for (std::string str : strs)
			s += std::to_string(str.length()) + '#' + str;
		return s;
	}
	
	std::vector<std::string> decode(std::string s) 
	{
		std::vector<std::string> strs;
		size_t n = s.length(), p = 0;
		while (p < n) 
		{
			size_t pos = s.find('#', p);
			if (pos == std::string::npos) 
				break;

			size_t length = stoi(s.substr(p, pos - p));//�õ��ַ�������
			strs.push_back(s.substr(pos + 1, length));
			p = pos + length + 1;
		}
		return strs;
	}
};