#include<vector>
#include<string>
#include<algorithm>
#include"TreeNode.h"
//��Ŀ����:����һ����ά�ַ������һ���ַ������飬�ж��ܷ��ڶ�ά�������ҵ���Щ�ַ������ڶ�ά������ֻ����������
//        Ѱ��
//�ⷨ����:��ǰ׺�������ַ��������е��ַ������ӿ�����ٶȡ�Ȼ��dfs����
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
			if (node == nullptr)//���ַ���Ӧ���ӽڵ㲻���ڣ��ʹ���һ���ӽڵ㣬���ӵ����ַ�
			{
				node = new TrieNode();
				current->setSon(word[i], node);
			}
			current = node; //currentָ���ӽڵ�
		}

		node->setEnd(); //������һ���ַ���֮��setEnd��ʾ�ַ�������
	}

	// Returns if the word is in the trie.
	bool search(std::string word)
	{
		TrieNode* current = root, *node = nullptr;
		for (int i = 0; i < word.size(); ++i)
		{
			node = current->getSon(word[i]);//���ҵ�ǰ�ַ���Ӧ���ӽڵ��Ƿ����
			if (node == nullptr)
				return false;
			current = node;
		}
		return node->isEnd(); //ע��������������ַ������ڣ�ҲҪ���ǲ���һ���ַ����Ľ�β
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
	std::string s, int i, int j, Trie& trie)//������
{
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
		return;
	if (visited[i][j])
		return;

	s += board[i][j];
	if (trie.search(s))//�ҵ�һ��Ԫ�أ���������
		result.push_back(s);
	
	if (!trie.startsWith(s))//��ǰ�ַ�������ǰ׺����
		return;
	else//��4������dfs����
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
	sort(result.begin(), result.end());//�����Ҫ����
	result.erase(unique(result.begin(), result.end()), result.end());//ȥ��
	return result;
}