#include<algorithm>
#include<vector>
#include<string>
//��Ŀ����������һ�����飬����Щ���������ƴ��������ʹ���γɵ����������[3, 30, 34, 5, 9]���γɵ������Ϊ9534330
//�ⷨ�������ؼ����ж�����������a��b���Ⱥ�˳���Ȱ�����ת��string��Ȼ��ͨ���Ƚ�a + b��b + a�Ĵ�С���жϣ� �Դ�������Ȼ�����ƴ�ӣ�ע��ȫ��0����� 

bool compare(const std::string& a, const std::string& b)
{
	return a + b > b + a;
}

std::string largestNumber(std::vector<int>& nums)
{
	std::vector<std::string> vec;
	for (int i = 0; i < nums.size(); ++i)
		vec.push_back(std::to_string(nums[i]));//ע�����������������ת����string

	std::sort(vec.begin(), vec.end(), compare);

	std::string result;
	for (int i = 0; i < vec.size(); ++i)//ƴ��
		result += vec[i];

	if (vec[0] == "0")//�ų�ȫ��0�����
		return vec[0];
	return result;
}