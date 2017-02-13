#include<string>
//��Ŀ����:����һ������n����7���Ʊ�ʾ������100�� 7���Ʊ�ʾΪ202��-10��ʾΪ"-10"
//�ⷨ����:���γ���7��ע�⸺����ע��0

std::string convertToBase7(int num)
{
	if (num == 0)
		return "0";

	std::string result;
	bool flag = false;
	if (num < 0)
		flag = true;

	int base = 7;
	num = abs(num);
	while (num)
	{
		result = std::to_string(num % base) + result;
		num /= base;
	}

	return flag ? "-" + result : result;
}