#include<string>
#include<algorithm>
#include<unordered_set>
//题目描述：给定两个整数，把这两个整数相除，结果用string的形式返回，循环部分用（）包围
//解法描述：先把int转换成long long防止溢出，处理一些特殊情况之后，转换成正数进行计算，注意判断出现循环的标准，不是小数部分出现重复数字，而是重复出现
//同一个除数去除被除数，这才叫循环了。

std::string fractionToDecimal(int numerator, int denominator)
{
	long long num = static_cast<long long>(numerator); //强制类型转换,这是为了防止出现溢出的情况，例如-2147483647，-1
	long long denomin = static_cast<long long>(denominator);

	if (num == 0) //处理特殊情况
		return "0";
	if (denomin == 1)
		return std::to_string(num);
	if (denomin == -1)
		return std::to_string(-num);

	std::string result;
	if ((num < 0 && denomin > 0) || (num > 0 && denomin < 0))//添加负号
		result += "-";

	num = abs(num);//全部转换成正数
	denomin = abs(denomin);
	long long val = num / denomin;
	result += std::to_string(val); //先求整数部分
	if (val * denomin == num)//刚好整除 直接返回
		return result;

	result += "."; //不能整数，加上小数点
	num = (num - val * denomin) * 10;
	int indexOfPoint = result.size() - 1;  //记录小数点的位置

	std::vector<long long> vec; //作为判断是否循环的标准，出现循环是numerator重复去除denominator，而不是余数重复出现，例如1,1000000
	while (num)
	{
		long long value = num / denomin;
		std::vector<long long>::iterator position = find(vec.begin(), vec.end(), num); //在小数点之后的部分进行查找，是否由重复数字出现
		if (position != vec.end()) //有重复数字出现，插入（和）
		{
			result.insert(result.begin() + indexOfPoint + 1 + (position - vec.begin()), '(');
			result += ")";
			break;
		}
		vec.push_back(num);
		result += std::to_string(value);
		num = (num - value * denomin) * 10;
	}
	return result;
}