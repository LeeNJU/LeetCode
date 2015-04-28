#include<string>
#include<vector>
//��Ŀ�������Ƚϰ汾�����֣�����0.1 < 1.1 < 1.2 < 13.37������ֻ�����ֺ͵�
//�ⷨ�������ָ��ַ�������vector����ÿ���Ӵ���Ȼ��ת����������һ�Ƚ�,ע��ĩβ��0�����
void split(std::vector<int>& vec, const std::string s)
{
	std::string str(s);
	while (str.find(".") != std::string::npos)
	{
		int index = str.find(".");
		vec.push_back(stoi(str.substr(0, index)));
		str = str.substr(index + 1);
	}
	vec.push_back(stoi(str));//���������ַ���vec��
	while (vec[vec.size() - 1] == 0)//������������0ȥ������ֹ����1.0 ��1�����
	{
		vec.pop_back();
	}
}

int compareVersion(std::string version1, std::string version2)
{
	std::vector<int> vec1, vec2;
	split(vec1, version1);
	split(vec2, version2);

	for (int i = 0; i < vec1.size() && i < vec2.size(); ++i)//ȡ��Ԫ����һ�Ƚ�
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