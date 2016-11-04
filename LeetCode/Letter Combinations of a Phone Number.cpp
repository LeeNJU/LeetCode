#include<string>
#include<vector>
#include<unordered_map>
//��Ŀ����������һ�������ַ�����ÿ�����ֶ�Ӧ�ֻ��ϵ���ĸ���ҳ����п��ܵ���ĸ��ϣ�����"23", ��Ϊ["ad", "ae", "af", 
//         "bd", "be", "bf", "cd", "ce", "cf"],��Ϊ����2��Ӧabc������3��Ӧdef
//�ⷨ�������ݹ飬��map������������ĸ�Ķ�Ӧ��ϵ���ݹ�Ĳ�����Ϊdigit���±�
void dfs(std::vector<std::string>& result, std::unordered_map<char, std::vector<char>>& data,
			std::string& digits, std::string temp, int depth)
{
	if (depth == digits.length())
	{
		result.push_back(temp); 
		return;
	}

	std::vector<char> t = data[digits[depth]];
	for (size_t i = 0; i < t.size(); ++i)
	{
		dfs(result, data, digits, temp + t[i], depth + 1);
	}
}

std::vector<std::string> letterCombinations(std::string digits)
{
	std::vector<std::string> result;
	if (digits.empty()) //�ų��������
		return result;

	std::unordered_map<char, std::vector<char>> data;
	data['2'] = { 'a', 'b', 'c' };
	data['3'] = {'d', 'e', 'f'};
	data['4'] = {'g', 'h', 'i'};
	data['5'] = {'j', 'k', 'l'};
	data['6'] = {'m', 'n', 'o'};
	data['7'] = {'p', 'q', 'r', 's'};
	data['8'] = {'t', 'u', 'v'};
	data['9'] = {'w', 'x', 'y', 'z'};
	dfs(result, data, digits, "", 0);
	return result;
}

