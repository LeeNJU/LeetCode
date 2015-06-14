#include<string>
#include<algorithm>
#include<unordered_set>
//��Ŀ������������������������������������������string����ʽ���أ�ѭ�������ã�����Χ
//�ⷨ������

std::string fractionToDecimal(int numerator, int denominator)
{
	if (numerator == 0)
		return "0";
	if (denominator == 1)
		return std::to_string(numerator);

	std::string result;
	if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))//��Ӹ���
		result += "-";

	long long num = static_cast<long long>(numerator);
	long long denomin = static_cast<long long>(denominator);
	num = abs(num);//ȫ��ת��������
	denomin = abs(denomin);
	int val = num / denomin;
	result += std::to_string(val); //������������
	if (val * denomin == num)//�պ����� ֱ�ӷ���
		return result;

	result += "."; //��������������С����
	num = (num - val * denomin) * 10;
	int indexOfPoint = result.size() - 1;  //��¼С�����λ��

	std::vector<int> vec; //��Ϊ�ж��Ƿ�ѭ���ı�׼������ѭ����numerator�ظ�ȥ��denominator
	while (num)
	{
		int value = num / denomin;
		std::vector<int>::iterator position = find(vec.begin(), vec.end(), num); //��С����֮��Ĳ��ֽ��в��ң��Ƿ����ظ����ֳ���
		if (position != vec.end()) //���ظ����ֳ��֣����루�ͣ�
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