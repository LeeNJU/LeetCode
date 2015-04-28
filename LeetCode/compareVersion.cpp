#include<string>
#include<vector>
//题目描述：比较版本号数字，例如0.1 < 1.1 < 1.2 < 13.37，假设只有数字和点
//解法描述：分割字符串，用vector保存每个子串，然后转换成数字逐一比较,注意末尾是0的情况
void split(std::vector<int>& vec, const std::string s)
{
	std::string str(s);
	while (str.find(".") != std::string::npos)
	{
		int index = str.find(".");
		vec.push_back(stoi(str.substr(0, index)));
		str = str.substr(index + 1);
	}
	vec.push_back(stoi(str));//把最后的数字放入vec中
	while (vec[vec.size() - 1] == 0)//把最后无意义的0去掉，防止出现1.0 和1的情况
	{
		vec.pop_back();
	}
}

int compareVersion(std::string version1, std::string version2)
{
	std::vector<int> vec1, vec2;
	split(vec1, version1);
	split(vec2, version2);

	for (int i = 0; i < vec1.size() && i < vec2.size(); ++i)//取出元素逐一比较
	{
		if (vec1[i] < vec2[i])
			return -1;
		else if (vec1[i] > vec2[i])
			return 1;
		else
			;
	}

	if (vec1.size() > vec2.size())
		return 1;
	else if (vec1.size() < vec2.size())
		return -1;
	else
		return 0;
}