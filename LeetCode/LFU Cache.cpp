#include<unordered_map>
#include<list>
//题目描述:实现LFU(least frequently used)算法，根据频率来淘汰cache的元素，频率最少的元素从cache中移除，每次
//        访问一个元素，该元素的访问频率加1
//解法描述:用节点表示有相同频率的key，用hashtable表示key，value，用另一个hashtable表示key，node*,表示这个key
//        存在的节点，每一个node根据频率排好序

struct Node //节点表示具有相同访问频率的key
{
	int count = 0;
	std::list<int> keys;
	Node* prev, *next;

	Node(int count):count(count), prev(nullptr), next(nullptr){};
};

class LFUCache 
{
private:
	Node* head;
	int capacity = 0;
	std::unordered_map<int, int> values;
	std::unordered_map<int, Node*> nodes;
	
	void increaseCount(int key) 
	{
		Node* node = nodes[key];
		node->keys.remove(key);

		if (node->next == nullptr) 
		{
			node->next = new Node(node->count + 1);
			node->next->prev = node;
			node->next->keys.push_back(key);
		}
		else if (node->next->count == node->count + 1) 
			node->next->keys.push_back(key);
		else 
		{
			Node* tmp = new Node(node->count + 1);
			tmp->keys.push_back(key);
			tmp->prev = node;
			tmp->next = node->next;
			node->next->prev = tmp;
			node->next = tmp;
		}

		nodes[key] = node->next;
		if (node->keys.size() == 0) 
			remove(node);
	}

	void removeOld() 
	{
		if (head == nullptr) 
			return;

		int old = 0;
		for (int n : head->keys) 
		{
			old = n;
			break;
		}

		head->keys.remove(old);
		if (head->keys.size() == 0) 
			remove(head);

		nodes.erase(old);
		values.erase(old);
	}

	void remove(Node* node) 
	{
		if (node->prev == nullptr) 
			head = node->next;
		else 
			node->prev->next = node->next;
		if (node->next != nullptr) 
			node->next->prev = node->prev;
	}

	void addToHead(int key) 
	{
		if (head == nullptr)
		{
			head = new Node(0);
			head->keys.push_back(key);
		}
		else if (head->count > 0)
		{
			Node* node = new Node(0);
			node->keys.push_back(key);
			node->next = head;
			head->prev = node;
			head = node;
		}
		else 
			head->keys.push_back(key);
		
		nodes[key] = head;
	}

public:
	LFUCache(int capacity) : head(nullptr), capacity(capacity){};

	int get(int key) 
	{
		if (values.find(key) != values.end())//节点存在，提高访问频率 
		{
			increaseCount(key);//提高访问频率，可能产生新的节点
			return values[key];
		}
		return -1;
	}

	void put(int key, int value) 
	{
		if (capacity == 0) 
			return;
		if (values.find(key) != values.end())
			values[key] = value;
		else //key不存在
		{
			if (values.size() < capacity) 
				values[key] = value;
			else 
			{
				removeOld();
				values[key] = value;
			}
			addToHead(key);
		}
		increaseCount(key);
	}
};