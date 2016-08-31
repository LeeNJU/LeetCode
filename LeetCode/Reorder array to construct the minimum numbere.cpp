#include<string>
#include<vector>
#include<algorithm>
//��Ŀ����:����һ���Ǹ��������飬������������У�ʹ��������ɵ�����С������[3, 32, 321],321323����С��
//�ⷨ����:�����򣬶���a��b�������֣����ab������ɵ����ֱ�ba������ɵ�����С����ôa����bǰ��

bool compare(int num1, int num2)
{
	std::string s1 = std::to_string(num1);
	std::string s2 = std::to_string(num2);

	return s1 + s2 < s2 + s1;
}
std::string minNumber(std::vector<int>& nums) 
{
	sort(nums.begin(), nums.end(), compare);
	std::string result = "";
	for (int num : nums)
		result += std::to_string(num);
	
	int index = 0; //Ҫע���ų���ǰ���0
	while (index < result.size() && result[index] == '0')
		++index;

	if (index == result.size())//ȫ����0
		return "0";

	return result.substr(index);
}