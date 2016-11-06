#include<vector>
#include<string>
#include<algorithm>
#include"TreeNode.h"
//题目描述:给定一个二维字符数组和一个字符串数组，判断能否在二维数组中找到这些字符串，在二维数组中只能上下左右
//        寻找
//解法描述:用前缀树保存字符串数组中的字符串，加快查找速度。然后dfs搜索
class Trie
{
private:
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(std::string word)
	{
		TrieNode* current = root, *node = nullptr;
		for (int i = 0; i < word.size(); ++i)
		{
			node = current->getSon(word[i]);
			if (node == nullptr)//该字符对应的子节点不存在，就创建一个子节点，连接到该字符
			{
				node = new TrieNode();
				current->setSon(word[i], node);
			}
			current = node; //current指向子节点
		}

		node->setEnd(); //插入完一个字符串之后，setEnd表示字符串结束
	}

	// Returns if the word is in the trie.
	bool search(std::string word)
	{
		TrieNode* current = root, *node = nullptr;
		for (int i = 0; i < word.size(); ++i)
		{
			node = current->getSon(word[i]);//查找当前字符对应的子节点是否存在
			if (node == nullptr)
				return false;
			current = node;
		}
		return node->isEnd(); //注意这里，就算所有字符都存在，也要看是不是一个字符串的结尾
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(std::string prefix)
	{
		TrieNode* current = root, *node = nullptr;
		for (int i = 0; i < prefix.size(); ++i)
		{
			node = current->getSon(prefix[i]);
			if (node == nullptr)
				return false;
			current = node;
		}
		return true;
	}
};

void dfs(std::vector<std::string>& result, std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited,
	std::string s, int i, int j, Trie& trie)//传引用
{
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
		return;
	if (visited[i][j])
		return;

	s += board[i][j];
	if (trie.search(s))//找到一个元素，继续搜索
		result.push_back(s);
	
	if (!trie.startsWith(s))//当前字符串不在前缀树中
		return;
	else//从4个方向dfs搜索
	{
		visited[i][j] = true;
		dfs(result, board, visited, s, i + 1, j, trie);
		dfs(result, board, visited, s, i - 1, j, trie);
		dfs(result, board, visited, s, i, j + 1, trie);
		dfs(result, board, visited, s, i, j - 1, trie);
		visited[i][j] = false;
	}
}

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
{
	std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
	std::vector<std::string> result;
	Trie trie;
	for (int i = 0; i < words.size(); ++i)
		trie.insert(words[i]);
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			std::string s;
			s += board[i][j];
			if (trie.startsWith(s))
				dfs(result, board, visited, "", i, j, trie);
		}
	}
	sort(result.begin(), result.end());//最后结果要排序
	result.erase(unique(result.begin(), result.end()), result.end());//去重
	return result;
}