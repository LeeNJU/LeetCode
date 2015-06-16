#include<string>
#include<algorithm>
#include<unordered_set>
//��Ŀ������������������������������������������string����ʽ���أ�ѭ�������ã�����Χ
//�ⷨ�������Ȱ�intת����long long��ֹ���������һЩ�������֮��ת�����������м��㣬ע���жϳ���ѭ���ı�׼������С�����ֳ����ظ����֣������ظ�����
//ͬһ������ȥ������������Ž�ѭ���ˡ�

std::string fractionToDecimal(int numerator, int denominator)
{
	long long num = static_cast<long long>(numerator); //ǿ������ת��,����Ϊ�˷�ֹ������������������-2147483647��-1
	long long denomin = static_cast<long long>(denominator);

	if (num == 0) //�����������
		return "0";
	if (denomin == 1)
		return std::to_string(num);
	if (denomin == -1)
		return std::to_string(-num);

	std::string result;
	if ((num < 0 && denomin > 0) || (num > 0 && denomin < 0))//��Ӹ���
		result += "-";

	num = abs(num);//ȫ��ת��������
	denomin = abs(denomin);
	long long val = num / denomin;
	result += std::to_string(val); //������������
	if (val * denomin == num)//�պ����� ֱ�ӷ���
		return result;

	result += "."; //��������������С����
	num = (num - val * denomin) * 10;
	int indexOfPoint = result.size() - 1;  //��¼С�����λ��

	std::vector<long long> vec; //��Ϊ�ж��Ƿ�ѭ���ı�׼������ѭ����numerator�ظ�ȥ��denominator�������������ظ����֣�����1,1000000
	while (num)
	{
		long long value = num / denomin;
		std::vector<long long>::iterator position = find(vec.begin(), vec.end(), num); //��С����֮��Ĳ��ֽ��в��ң��Ƿ����ظ����ֳ���
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