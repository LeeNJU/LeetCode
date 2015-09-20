#include<string>
#include "TreeNode.h"
#include<vector>
//题目描述：实现前缀树
//解法描述：(个人理解)边用来存储字符，每一个节点有26个指针，指向不同的子节点，nullptr表示子节点不存在

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