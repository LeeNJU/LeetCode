#include<string>
#include<vector>
#include "TreeNode.h"
//��Ŀ����:����һ�����ݽṹ�����Զ��ַ���������Ӻ�������֧������ƥ������������'.'��ʾ�����ַ�
//�ⷨ����:��trie tree,��Ӳ�����trie treeһ������������ʱ���������'.'�ͽ��еݹ�������û������'.'�ͽ�����������
class WordDictionary
{
private:
	TrieNode* root;
	bool searches(TrieNode* current, std::string& word, int index)
	{
		if (current == nullptr)
			return false;
		if (index == word.size())
			return current->isEnd();//Ҫ����ǰ�ڵ��ǲ����ַ����Ľ�β

		TrieNode* node = nullptr;
		for (int i = index; i < word.size(); ++i)
		{
			if (word[i] != '.')//�������'.',�Ͱ��������ķ�ʽ��������
			{
				node = current->getSon(word[i]);
				if (node == nullptr)//û������ַ���ֱ�ӷ���false
					return false;
				else
					current = node;
			}
			else//����'.',���õݹ�ķ�ʽ��������
			{
				std::vector<TrieNode*> children = current->getChildren();
				for (int j = 0; j < children.size(); ++j)
				{
					if (children[j] != nullptr)//��ÿһ����null�Ľڵ���еݹ�����
					{
						bool existed = searches(children[j], word, i + 1);
						if (existed)//�������Ϊtrue,ֱ�ӷ���
							return true;
					}
				}
				return false; //ע������ݹ�����֮�����û�з���true,˵��û�и��ַ���������false
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
		current->setEnd();//���Ҫ���ַ�����Ϊ��β
	}

	bool search(std::string word)
	{
		return searches(root, word, 0);
	}
};
