#include<string>
#include<algorithm>
//给定两个非负数字字符串，计算这两个字符串的乘积
//解法：按照乘法规则进行计算，先对字符串进行反转方便计算，注意记录用哪一位去乘，例如98*76，先用8去乘7和6，占据个位和十位，再用9去乘7和6，占据十位和百位，要用变量记录
std::string multiply(std::string num1, std::string num2)
{
	if (num1 == "0" || num2 == "0")//排除等于0的情况
		return "0";

	std::string result;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int carry = 0;//表示进位
	for (int i = 0; i < num1.size(); ++i)
	{
		int index = i;//index用来表示是用哪一位(个位，十位...)去乘以num2,并且作为给result赋值的下标
		for (int j = 0; j < num2.size(); ++j)//每一个迭代向result中赋一个值
		{
			int value = (num1[i] - '0') * (num2[j] - '0') + carry;
			if (index < result.size())
			{
				value += result[index] -  '0';
				result[index] = value % 10 + '0';
			}
			else//表示位数多了，需要增加长度
			{
				result.append(1, value % 10 + '0');
			}

			carry = value / 10;
			++index;
		}
		if (carry)
			result.append(1, carry + '0');//第一次迭代乘完之后,检查可能有进位，例如99*99

		carry = 0;
	}

	reverse(result.begin(), result.end());
	return result;
}