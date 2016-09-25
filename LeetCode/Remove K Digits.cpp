#include<string>
//��Ŀ����:����һ���ַ�����ʾһ�����֣�ȥ�����е�k�����֣�ʹ��ʣ�µ���������С�ģ�����"1432219",k = 3,ȥ��
//        3������֮��õ�����С������1219
//�ⷨ����:�����ַ���������ÿ���ַ�������Ƚ���ַ��������һ���ַ�ҪС��˵�����滻���һ���ַ�����ɸ�С��
//        ���֣��滻ĩβ�ȵ�ǰ�ַ�����ַ������������滻֮�󣬵õ����ַ����������ǵ������ַ���

std::string removeKdigits(std::string num, int k) 
{
	std::string result = "";
	int n = num.size(), keep = n - k;
	for (char c : num) 
	{
		while (k && result.size() && result.back() > c) 
		{
			result.pop_back();
			--k;
		}
		result.push_back(c);
	}

	result.resize(keep);//ע������Ҫresize����Ϊ����ɾ�����ַ�������k�������õ����ǵ�������
	while (!result.empty() && result[0] == '0')//ȥ��ǰ���0 
		result.erase(result.begin());
	
	return result.empty() ? "0" : result;
}