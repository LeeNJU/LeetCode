#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
//��Ŀ����������һ����ʼ���ʣ�һ����ֹ���ʺ�һ���ֵ䣬ÿ�ΰ���ʼ���ʱ任һ���ַ�������ʼ���ʱ任����ֹ���ʣ�����ÿ�α任�õ����м���ɵ��ʱ������ֵ�
//         ���ܹ��ҵ�������С�ı任����
//�ⷨ������������ȱ������ö��У�������a��zȥ������ʼ���ʵ�ÿ��Ԫ�أ��жϵõ����м䵥���Ƿ����ֵ��У�����ڣ����뵽�����У�����Ҫע���¼���ʵĲ���

int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordDict)
{
	std::queue<std::pair<std::string, int>> que;
	que.push(std::pair<std::string, int>(beginWord, 1)); //��¼ÿ�������Լ���Ӧ�Ĳ���
	while (!que.empty())
	{
		std::pair<std::string, int> word = que.front();
		que.pop();
		if (word.first == endWord) //�ҵ�Ŀ�굥����
			return word.second;

		for (int i = 0; i < word.first.size(); ++i)
		{
			char temp = word.first[i];
			for (int j = 'a'; j <= 'z'; ++j) //�ֱ���a��zȥ�滻�����ֵ��в����Ƿ���ڸõ���
			{
				word.first[i] = j;
				if (wordDict.find(word.first) != wordDict.end())
				{
					que.push(std::pair<std::string, int>(word.first, word.second + 1));
					wordDict.erase(word.first);//�ҵ��õ��ʣ����ֵ���ɾ��
				}
			}
			word.first[i] = temp; //�ָ�����
		}
	}
	return 0;
}