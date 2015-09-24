#include<iostream>
#include<string>
#include<algorithm>
//��Ŀ�������������������ַ��������������ַ������ն����ƽ�����ӣ����ؽ��
//�ⷨ����������ָ��ֱ�������������ַ���������ӣ����ѽ����ת

std::string addBinary(std::string a, std::string b)
{
	std::string result;
	int carry = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j)
	{
		const int ai = i < 0 ? 0 : a[i] - '0';
		const int bi = j < 0 ? 0 : b[j] - '0';
		const int value = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.push_back(value + '0');
	}
	if (carry == 1)//���Ľ�λ
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}