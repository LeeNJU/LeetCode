#include<unordered_set>
//��Ŀ����:����һ������n���ж��Ƿ���happy number�� ����19��happy number��
//�ⷨ����:�ù�ϣset�����м������ֵ
bool isHappy(int n)
{
	std::unordered_set<int> s;
	while (s.find(n) == s.end())
	{
		s.insert(n);
		int value = 0;
		while (n)
		{
			int digit = n % 10;
			n /= 10;
			value += digit * digit;
		}
		n = value;
		if (n == 1)
			return true;
	}
	return false;
}