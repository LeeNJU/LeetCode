#include<string>
//��Ŀ����:����һ���ַ�����ʾһ��С��������ת���ɶ�������ʽ������"3.5"ת����"11.1",���С�����ֲ�����32���ַ���ʾ������
//        "ERROR"
//�ⷨ����:�ֱ�õ��������ֺ�С�����֣�ת���ɶ����ƣ�ע��edge cases
std::string integer_binary(int n)//������ת���ɶ�����
{
	std::string s = "";
	while (n)
	{
		if (n % 2 == 0)
			s += "0";
		else
			s += "1";

		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

std::string fraction_binary(double num)//��С��ת���ɶ�����
{
	std::string s = "";
	while (num)
	{
		num *= 2;
		if (num >= 1)
		{
			num -= 1;
			s += "1";
		}
		else
			s += "0";

		if (s.size() > 32)
			return "ERROR";
	}
	return s;
}
std::string binaryRepresentation(std::string n) 
{
	int index = n.size();
	for (int i = 0; i < n.size(); ++i)//�ҵ�С�����λ��
	{
		if (n[i] == '.')
		{
			index = i;
			break;
		}
	}

	std::string integer = integer_binary(stoi(n.substr(0, index)));//�õ��������ֵĶ����Ʊ�ʾ
	if (index == n.size())//û��С������
		return integer;

	std::string result;
	if (integer == "")//����������0
		result += "0" + integer;
	else
		result = integer;

	std::string fraction = "0" + n.substr(index);
	fraction = fraction_binary(atof(fraction.c_str()));//�õ�С�����ֵĶ����Ʊ�ʾ
	
	if (fraction == "ERROR")
		return "ERROR";
	else if (fraction == "")//С������Ϊ0
		return result;
	else
		return result + "." + fraction;
}