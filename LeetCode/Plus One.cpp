#include<vector>
//��Ŀ����������һ���Ǹ������ʾһ���ܴ���������������1
//�ⷨ������������飬ע���λ��ȡģ
std::vector<int> plusOne(std::vector<int> &digits)
{
	int carry = 1;
	for (std::vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ++iter)
	{
		*iter += carry;
		carry = *iter / 10;//��ǰ��λ
		*iter %= 10;//ȡģ
	}
	if (carry > 0)
		digits.insert(digits.begin(), 1);

	return digits;
}