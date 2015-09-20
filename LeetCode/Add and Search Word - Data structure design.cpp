#include<string>
#include<vector>
#include "TreeNode.h"
class WordDictionary 
{
private:
	TrieNode* root;
	bool searches(TrieNode* current, std::string& word, int index)
	{
		if (current == nullptr)
			return false;
		if (index == word.size())
			return true;

		std::vector<TrieNode*> children = current->getChildren();
		bool result = false;
		for (int i = 0; i < children.size(); ++i)
		{
			if (children[i] != nullptr)
			{
				if (word[index] == '.' || word[index] == ('a' + i))
					result = searches(children[i], word, index + 1);
				
			}
		}
		return result;
	}
public:
	WordDictionary()
	{
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(std::string word) 
	{
		TrieNode* current = root, *node = nullptr;
		for (int i = 0; i < word.size(); ++i)
		{
			node = current->getSon(word[i]);
			if (node == nullptr)
			{
				node = new TrieNode();
				current->setSon(word[i], node);
			}
			current = node;
		}
		current->setEnd();
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(std::string word) 
	{
		return searches(root, word, 0);
	}
};