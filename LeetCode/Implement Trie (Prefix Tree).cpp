#include<string>
#include<vector>
//��Ŀ������ʵ��ǰ׺��
//�ⷨ������(�������)�������洢�ַ���ÿһ���ڵ���26��ָ�룬ָ��ͬ���ӽڵ㣬nullptr��ʾ�ӽڵ㲻����
class TrieNode 
{
private:
	bool isWord; // �����Ƿ���һ���ַ����Ľ���
	std::vector<TrieNode*> children; //�ӽڵ�ָ��
public:
	TrieNode() :children(26, nullptr)
	{
		this->isWord = false;
	}

	void setEnd()
	{
		isWord = true;
	}

	bool isEnd()
	{
		return isWord;
	}

	TrieNode* getSon(char c)
	{
		return children[c - 'a'];
	}
	TrieNode* setSon(char c, TrieNode* node)
	{
		children[c - 'a'] = node;
	}
};

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