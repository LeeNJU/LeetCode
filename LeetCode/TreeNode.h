#include<vector>
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class DoublyListNode 
{
public:
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode(int val) 
	{
		this->val = val;
		this->prev = this->next = nullptr;
	}
};

class SegmentTreeNode 
{
public:
	int start, end, max, count, sum;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int m = 0, int c = 0, int s = 0) 
	{
		this->start = start;
		this->end = end;
		this->max = m;
		this->count = c;
		this->sum = s;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct TreeLinkNode
{
	int val;
	TreeLinkNode* left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr){}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class TrieNode
{
private:
	bool isWord; // 表明是否是一个字符串的结束
	std::vector<TrieNode*> children; //子节点指针
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
	std::vector<TrieNode*> getChildren()
	{
		return children;
	}
	TrieNode* setSon(char c, TrieNode* node)
	{
		children[c - 'a'] = node;
	}
};

class Iterator
{
private:
	int* pointer;
public:
	bool hasNext()
	{
		return pointer != nullptr;
	}
	int getNext()
	{
		int result = *pointer;
		++pointer;
		return result;
	}
};