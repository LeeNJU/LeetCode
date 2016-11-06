#include<string>
#include<vector>
#include "TreeNode.h"
//题目描述:定义一个数据结构，可以对字符串进行添加和搜索，支持正则匹配搜索，碰到'.'表示任意字符
//解法描述:用trie tree,添加操作和trie tree一样，在搜索的时候，如果碰到'.'就进行递归搜索，没有碰到'.'就进行
//        正常搜索
class WordDictionary
{
private:
	TrieNode* root;
	bool searches(TrieNode* current, std::string& word, int index)
	{
		if (current == nullptr)
			return false;
		if (index == word.size())
			return current->isEnd();//要看当前节点是不是字符串的结尾

		TrieNode* node = nullptr;
		for (int i = index; i < word.size(); ++i)
		{
			if (word[i] != '.')//如果不是'.',就按照正常的方式进行搜索
			{
				node = current->getSon(word[i]);
				if (node == nullptr)//没有这个字符，直接返回false
					return false;
				else
					current = node;
			}
			else//碰到'.',就用递归的方式进行搜索
			{
				std::vector<TrieNode*> children = current->getChildren();
				for (int j = 0; j < children.size(); ++j)
				{
					if (children[j] != nullptr)//对每一个非null的节点进行递归搜索
					{
						bool existed = searches(children[j], word, i + 1);
						if (existed)//搜索结果为true,直接返回
							return true;
					}
				}
				return false; //注意这里，递归搜索之后如果没有返回true,说明没有该字符串，返回false
			}
		}
		return current->isEnd();
	}
public:
	WordDictionary()
	{
		root = new TrieNode();
	}
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
		current->setEnd();//最后要把字符串设为结尾
	}

	bool search(std::string word)
	{
		return searches(root, word, 0);
	}
};
