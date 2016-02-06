#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ���ַ������飬�������²���:"eqdf"��ÿ���ַ����滻����ĸ���е���һ���ַ�,����һ�α任�õ�
//        "freg",���Լ����任�����ڶ��ַ��������е��ַ������з��飬�ǵ�ͬһ���ڵĶ�����ͬһ���任
//�ⷨ����:��map����ÿ���ַ�������������ַ�������Ϊkey
std::string shift(const std::string &str)
{
	std::string res = "";
	for (int i = 1; i < str.size(); ++i)
	{
		int diff = str[i] - str[i - 1];
		if (diff < 0)
			diff += 26;
		res += diff + 'a' + ',';
	}
	return res;
}

std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings) 
{
	std::vector<std::vector<std::string>> result;
	std::unordered_map<std::string, std::vector<std::string>> mp;
	for (auto str : strings) 
		mp[shift(str)].emplace_back(str);

	std::vector<std::vector<std::string>> res;
	for (auto elem : mp) 
	{
		if (elem.second.size() > 0) 
		{
			sort(elem.second.begin(), elem.second.end());
			res.emplace_back(elem.second);
		}
	}
	return res;
}
