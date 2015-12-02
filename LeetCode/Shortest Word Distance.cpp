#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

//题目描述:给定一个字符串数组和两个字符串，找到这两个字符串在数组中的最近距离，数组中有重复元素，例如
//        ["practice", "makes", "perfect", "coding", "makes"],"makes"和"coding"的最近距离是1
//解法描述:扫一遍，记录word的下标，同时记录最短距离
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
}

//version2
//题目描述:现在这个方法要被重复的调用，如何优化
//解法描述:用hashmap存下标，然后再找
class WordDistance 
{
private:
	std::unordered_map<std::string, std::vector<int>> wordInd;
public:
	WordDistance(std::vector<std::string> words)//存每个word的下标 
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
		while (i < m && j < n) //找到下标差的最小值
		{
			dist = std::min(dist, abs(indexes1[i] - indexes2[j]));
			if (indexes1[i] < indexes2[j]) 
				i++;
			else 
				j++;
		}
		return dist;
	}
};

//version3
//题目描述:跟第一题一样，只是word1和word2可能是一样的
//解法描述:跟第一题解法类似，不过要判断下标是否相等
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