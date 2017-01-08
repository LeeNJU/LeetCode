#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
//��Ŀ����:����һ���ַ�����ʾ����ÿ�ο��԰�һ����������һ��������������Ҫ���ٲ���һ���ַ�����������
//        һ���ַ�����������start:"AACCGGTT", end:"AACCGGTA", bank:["AACCGGTA"],ֻ��Ҫһ���Ϳ��԰�start
//        �ַ������end�ַ������任�����е��ַ���������bank��
//�ⷨ����:���ѣ�������word ladder

int minMutation(std::string start, std::string end, std::vector<std::string>& bank) 
{
	std::unordered_set<std::string> set(bank.begin(), bank.end());
	std::queue<std::pair<std::string, int>> queue;
	queue.push(std::pair<std::string, int>(start, 0));

	while (!queue.empty())
	{
		std::pair<std::string, int> pair = queue.front();
		queue.pop();

		if (pair.first == end)
			return pair.second;

		std::string genes = "ACGT";
		std::string s = pair.first;
		for (int i = 0; i < s.size(); ++i)
		{
			char original = s[i];
			for (char c : genes)
			{
				if (c == original)
					continue;

				s[i] = c;
				if (set.find(s) != set.end())
				{
					queue.push(std::pair<std::string, int>(s, pair.second + 1));
					set.erase(s);
				}
			}
			s[i] = original;
		}
	}
	return -1;
}