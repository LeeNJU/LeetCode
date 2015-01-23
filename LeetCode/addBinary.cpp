#include<iostream>
#include<string>
#include<algorithm>
//�������������ַ��������������ַ������ն����ƽ�����ӣ����ؽ��
//�ⷨ���ȷ�ת�����ַ�����Ȼ������ָ��ֱ���������ַ����������

std::string addBinary(std::string a, std::string b)
{
	std::string result;
	const size_t length = a.size() > b.size() ? a.size() : b.size();//����ȡ���
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i < length; ++i)
	{
		const int ai = i < a.size() ? a[i] - '0' : 0;//����±곬���ַ������ȣ�����0���棬�������ַ����е�ֵ
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int value = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), value + '0');
	}

	if (carry == 1)//���Ľ�λ
		result.insert(result.begin(), '1');
	return result;
}