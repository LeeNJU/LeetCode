#include<vector>
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
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