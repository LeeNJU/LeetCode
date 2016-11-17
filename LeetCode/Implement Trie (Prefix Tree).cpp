#include<string>
#include"TreeNode.h"
#include<vector>
//��Ŀ������ʵ��ǰ׺��
//�ⷨ������(�������)�������洢�ַ���ÿһ���ڵ���26��ָ�룬ָ��ͬ���ӽڵ㣬nullptr��ʾ�ӽڵ㲻����

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