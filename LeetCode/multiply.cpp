#include<string>
#include<algorithm>
//���������Ǹ������ַ����������������ַ����ĳ˻�
//�ⷨ�����ճ˷�������м��㣬�ȶ��ַ������з�ת������㣬ע���¼����һλȥ�ˣ�����98*76������8ȥ��7��6��ռ�ݸ�λ��ʮλ������9ȥ��7��6��ռ��ʮλ�Ͱ�λ��Ҫ�ñ�����¼
std::string multiply(std::string num1, std::string num2)
{
	if (num1 == "0" || num2 == "0")//�ų�����0�����
		return "0";

	std::string result;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int carry = 0;//��ʾ��λ
	for (int i = 0; i < num1.size(); ++i)
	{
		int index = i;//index������ʾ������һλ(��λ��ʮλ...)ȥ����num2,������Ϊ��result��ֵ���±�
		for (int j = 0; j < num2.size(); ++j)//ÿһ��������result�и�һ��ֵ
		{
			int value = (num1[i] - '0') * (num2[j] - '0') + carry;
			if (index < result.size())
			{
				value += result[index] -  '0';
				result[index] = value % 10 + '0';
			}
			else//��ʾλ�����ˣ���Ҫ���ӳ���
			{
				result.append(1, value % 10 + '0');
			}

			carry = value / 10;
			++index;
		}
		if (carry)
			result.append(1, carry + '0');//��һ�ε�������֮��,�������н�λ������99*99

		carry = 0;
	}

	reverse(result.begin(), result.end());
	return result;
}