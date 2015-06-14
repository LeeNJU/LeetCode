#include<string>
#include<algorithm>
#include<unordered_set>
//题目描述：给定两个整数，把这两个整数相除，结果用string的形式返回，循环部分用（）包围
//解法描述：

std::string fractionToDecimal(int numerator, int denominator)
{
	if (numerator == 0)
		return "0";
	if (denominator == 1)
		return std::to_string(numerator);

	std::string result;
	if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))//添加负号
		result += "-";

	long long num = static_cast<long long>(numerator);
	long long denomin = static_cast<long long>(denominator);
	num = abs(num);//全部转换成正数
	denomin = abs(denomin);
	int val = num / denomin;
	result += std::to_string(val); //先求整数部分
	if (val * denomin == num)//刚好整除 直接返回
		return result;

	result += "."; //不能整数，加上小数点
	num = (num - val * denomin) * 10;
	int indexOfPoint = result.size() - 1;  //记录小数点的位置

	std::vector<int> vec; //作为判断是否循环的标准，出现循环是numerator重复去除denominator
	while (num)
	{
		int value = num / denomin;
		std::vector<int>::iterator position = find(vec.begin(), vec.end(), num); //在小数点之后的部分进行查找，是否由重复数字出现
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