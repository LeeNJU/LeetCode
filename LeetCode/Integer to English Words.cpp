#include<string>
#include<vector>
//��Ŀ����:����һ���Ǹ����֣�������ת����Ӣ�ı�ʾ��ʽ������123������"One Hundred Twenty Three"��12345����
//        "Twelve Thousand Three Hundred Forty Five"
//�ⷨ����:ÿ3λ���ֿ���һ��group��ʹ��digits��tens���飬Ȼ��ݹ�

std::string int2string(int n, const std::vector<std::string>& digits, 
						const std::vector<std::string>& tens) 
{
	if (n >= 1000000000) 
		return int2string(n / 1000000000, digits, tens) + " Billion" + int2string(n % 1000000000, digits, tens);
	else if (n >= 1000000) 
		return int2string(n / 1000000, digits, tens) + " Million" + int2string(n % 1000000, digits, tens);
	else if (n >= 1000) 
		return int2string(n / 1000, digits, tens) + " Thousand" + int2string(n % 1000, digits, tens);
	else if (n >= 100) 
		return int2string(n / 100, digits, tens) + " Hundred" + int2string(n % 100, digits, tens);
	else if (n >= 20) 
		return  " " + tens[n / 10] + int2string(n % 10, digits, tens);
	else if (n >= 1) 
		return " " + digits[n];
	else 
		return "";
}

std::string numberToWords(int num) 
{
	if (num == 0) 
		return "Zero";
	else 
	{
		std::vector<std::string> digits = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", 
			"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
			"Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		std::vector<std::string> tens = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", 
			"Sixty", "Seventy", "Eighty", "Ninety" };
		std::string result= int2string(num, digits, tens);
		return result.substr(1, result.length() - 1);
	}
}