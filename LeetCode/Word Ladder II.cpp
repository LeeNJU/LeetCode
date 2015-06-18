#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>

//��Ŀ����������һ����ʼ���ʣ�һ����ֹ���ʺ�һ���ֵ䣬ÿ�ΰ���ʼ���ʱ任һ���ַ�������ʼ���ʱ任����ֹ���ʣ�����ÿ�α任�õ����м���ɵ��ʱ������ֵ�
//         ���ܹ��ҵ�������ϸ�ı任����
//�ⷨ������������ȱ������ö��У�������a��zȥ������ʼ���ʵ�ÿ��Ԫ�أ��жϵõ����м䵥���Ƿ����ֵ��У�����ڣ����뵽�����У�����Ҫע���¼���ʵĲ���

void dfs(std::vector<std::vector<std::string>>& result, std::vector<std::string> intermediate, const std::string& start, const std::string& end, std::unordered_map<std::string, std::vector<std::string>>& dict)
{
	if (start == end)
	{
		result.push_back(intermediate);
		return;
	}

	for (int i = 0; i < dict[start].size(); ++i)
	{
		intermediate.insert(intermediate.begin(), dict[start][i]);
		dfs(result, intermediate, dict[start][i], end, dict);
		intermediate.erase(intermediate.begin());
	}
}

std::vector<std::vector<std::string>> findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
{
	std::vector<std::vector<std::string>> result;
	std::queue<std::string> que;
	std::unordered_map<std::string, std::vector<std::string>> prev; //��¼ÿ�����ʵĸ��ڵ�
	que.push(start);
	prev[start] = std::vector<std::string>();
	bool found = false; //�ж��Ƿ��н�
	dict.erase(start);
	while (!que.empty())
	{
		std::string word = que.front();
		que.pop();
		if (word == end)
			found = true;

		std::string prevWord = word;
		for (int i = 0; i < word.size(); ++i)
		{
			char temp = word[i];
			for (int j = 'a'; j <= 'z'; ++j) //�ֱ���a��zȥ�滻�����ֵ��в����Ƿ���ڸõ���
			{
				if (word[i] == static_cast<char>(j))
					continue;
				word[i] = j;
				if (dict.find(word) != dict.end())
				{
					que.push(word);
					prev[word].push_back(prevWord);
				}
			}
			word[i] = temp; //�ָ�����
		}
	}
	if (found)
	{
		std::vector<std::string> intermediate;
		intermediate.push_back(end);
		dfs(result, intermediate, end, start, prev);
	}
	return result;
}