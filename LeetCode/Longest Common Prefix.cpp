#include<string>
#include<vector>
//��Ŀ����������һ���ַ������飬�ҵ���Щ�ַ�������Ĺ���ǰ׺
//�ⷨ�������Ե�һ���ַ���Ϊ�걾����һ�Ƚ�ÿ���ַ����ĵ�һ��Ԫ���Ƿ���ȣ��ٱȽϵڶ���Ԫ���Ƿ����
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
	if (strs.empty())
		return "";

	for (int i = 0; i < strs[0].size(); ++i)
	{
		for (int j = 1; j < strs.size(); ++j)
		    if (strs[j][i] != strs[0][i])
				return strs[0].substr(0, i);
	}
	return strs[0];
}