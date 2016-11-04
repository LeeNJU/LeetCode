#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
//��Ŀ����:����һ���ַ����������ַ���Ƶ�ʽ�������Ƶ�ʸߵĳ�����ǰ�棬�������"tree",����"eert"����"eetr"
//�ⷨ����:ͳ���ַ���Ƶ�ʣ�Ȼ������

std::string frequencySort(std::string str) 
{
	std::unordered_map<char, int> map;
	for (char c : str)
		++map[c];

	std::vector<std::pair<int, char>> vec;
	auto iter = map.begin();
	while (iter != map.end())
	{
		vec.push_back(std::pair<int, char>(iter->second, iter->first));
		++iter;
	}

	std::string result = "";
	std::sort(vec.begin(), vec.end());
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		auto pair = vec[i];
		int index = 0;
		while (index < pair.first)
		{
			result += pair.second;
			++index;
		}
	}
	return result;
}