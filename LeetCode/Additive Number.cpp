#include<string>
#include<vector>
//��Ŀ����:����һ�������ַ������ж����ǲ���additive number������"112358"��additive number����Ϊ���Ա��ֳ�
//        "1", "1", "2", "3", "5", "8"��������1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8��������0��ͷ��
//        �����ַ����ǷǷ��ַ���������"02"
//�ⷨ����:��ö�ٵ�һ�����͵ڶ�������Ȼ����������ӣ��ݹ��ж�ʣ�µ��ַ����Ƿ����������֮�͡�

bool isValid(std::string num1, std::string num2, std::string num)
{   //�Ƿ��ַ���
	if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') 
		return false;
	
	std::string sum = std::to_string(std::stol(num1) + std::stol(num2));
	if (num == sum) 
		return true;
	if (num.size() < sum.size() || sum.compare(num.substr(0, sum.size())) != 0) 
		return false;
	else 
		return isValid(num2, sum, num.substr(sum.size()));//�ݹ��ж�
}

bool isAdditiveNumber(std::string num) 
{   //i��j�����һ�͵ڶ������ĳ���
	for (int i = 1; i <= num.size() / 2; ++i)//��һ�����ĳ��ȿ϶����ᳬ���ַ����ĵ�һ��
	{
		for (int j = 1; j <= (num.size() - i) / 2; ++j)//�ڶ������ĳ���Ҳ���ᳬ��ʣ���ַ�����һ��
		{
			if (isValid(num.substr(0, i), num.substr(i, j), num.substr(i + j))) 
				return true;
		}
	}
	return false;
}