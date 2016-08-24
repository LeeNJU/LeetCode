#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

//��Ŀ����:����һ���ַ�������������ַ������ҵ��������ַ����������е�������룬���������ظ�Ԫ�أ�����
//        ["practice", "makes", "perfect", "coding", "makes"],"makes"��"coding"�����������1
//�ⷨ����:ɨһ�飬��¼word���±꣬ͬʱ��¼��̾���
int shortestDistance(std::vector<std::string>& words, std::string word1, std::string word2)
{
	int min_distance = INT_MAX, index1 = -1, index2 = -1;
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == word1)
			index1 = i;
		else if (words[i] == word2)
			index2 = i;

		if (index1 != -1 && index2 != -1)
			min_distance = std::min(abs(index1 - index2), min_distance);
	}
	return min_distance;
}

//version2
//��Ŀ����:�����������Ҫ���ظ��ĵ��ã�����Ż�
//�ⷨ����:��hashmap���±꣬Ȼ������
class WordDistance 
{
private:
	std::unordered_map<std::string, std::vector<int>> wordInd;
public:
	WordDistance(std::vector<std::string> words)//��ÿ��word���±� 
	{
		for (int i = 0; i < words.size(); i++)
			wordInd[words[i]].push_back(i);
	}
	
	int shortest(std::string word1, std::string word2) 
	{
		std::vector<int> indexes1 = wordInd[word1];    
		std::vector<int> indexes2 = wordInd[word2];
		int m = indexes1.size(), n = indexes2.size();
		int i = 0, j = 0, dist = INT_MAX;
		while (i < m && j < n) //�ҵ��±�����Сֵ
		{
			dist = std::min(dist, abs(indexes1[i] - indexes2[j]));
			if (indexes1[i] < indexes2[j]) 
				++i;
			else 
				++j;
		}
		return dist;
	}
};

//version3
//��Ŀ����:����һ��һ����ֻ��word1��word2������һ����
//�ⷨ����:����һ��ⷨ���ƣ�����Ҫ�ж��±��Ƿ����
int shortestDistance3(std::vector<std::string>& words, std::string word1, std::string word2)
{
	int min_distance = INT_MAX, index1 = -1, index2 = -1;
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == word1)
		{
			index1 = i;
			if (index2 != -1)
				min_distance = (index1 == index2 ? min_distance : std::min(abs(index1 - index2), min_distance));
		}

		if (words[i] == word2)
		{
			index2 = i;
			if (index1 != -1)
				min_distance = (index1 == index2 ? min_distance : std::min(abs(index1 - index2), min_distance));
		}
	}
	return min_distance;
}