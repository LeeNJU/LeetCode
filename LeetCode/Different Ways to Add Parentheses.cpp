#include<vector>
#include<string>
//��Ŀ����:����һ���ַ���������2-1-1��������ţ�ʹ�������ֵ��ͬ�����ж����ֲ�ͬ�Ľ��
//�ⷨ����:�ݹ飬���������Ϊ���Ľ��л��֣���������߷ֱ������ͬ����ֵ����ֵ��Ȼ�������ֵ����ֵ�ļ��ϣ����м���
//        Ӧ��Ҫ���Ǽ�������Ψһ��
std::vector<int> diffWaysToCompute(std::string input) 
{
	std::vector<int> result;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*')
		{
			std::vector<int> left_value = diffWaysToCompute(input.substr(0, i));//����������ţ������߽��л���
			std::vector<int> right_value = diffWaysToCompute(input.substr(i + 1));
			for (int m = 0; m < left_value.size(); ++m)//����ֵ����ֵ���м���
			{
				for (int n = 0; n < right_value.size(); ++n)
				{
					if (input[i] == '+')
						result.push_back(left_value[m] + right_value[n]);
					else if (input[i] == '-')
						result.push_back(left_value[m] - right_value[n]);
					else if (input[i] == '*')
						result.push_back(left_value[m] * right_value[n]);
				}
			}
		}
	}

	if (result.empty())//resultΪ�գ�˵��û���������input����һ������������
		result.push_back(stoi(input));
	return result;
}
