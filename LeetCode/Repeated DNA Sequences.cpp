#include<vector>
#include<string>
#include<unordered_map>

//��Ŀ����������һ��DNA�ַ�����ֻ����C��G��A��T�ַ����ҵ����г��ִ�������1�ĳ���Ϊ10���Ӵ�
//�ⷨ��������λ��������2λ�Ϳ��Զ�CGAT���б��룬����Ϊ10���Ӵ�ֻ��Ҫһ��int��20λ�Ϳ����ˣ���hashtable����ÿ��ֵ���ֵĴ�����ע��Ҫȥ���ظ�Ԫ��

int getValue(char c)
{
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	else return 3;
}

std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
	std::vector<std::string> result;
	if (s.size() < 10)
		return result;

	std::unordered_map<int, int> m;
	int value = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		value = ((value << 2) | getValue(s[i])) & 0x000ffff; //ע�����һ��int�ĺ�20λ����Ч�ģ������ƶ�2λ����Ϊ�˰Ѻ�һ���ַ���ֵ��
		                                                      //����ȥ��Ȼ����������ѳ�����20λ��λ��Ϊ0
		if (i == 9)  //��һ��Ԫ��
			++m[value];
		if (i > 9)
		{
			++m[value];
			if (m[value] > 1)
			{
				result.push_back(s.substr(i - 9, 10));
				m[value] = INT_MIN;  //����ע�⣬��ΪINT_MIN��Ϊ�˷�ֹ�����ظ�Ԫ�أ�����һ���Ӵ�����100��
			}
		}
	}
	return result;
}