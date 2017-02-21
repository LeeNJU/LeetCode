#include<unordered_map>
#include<list>
//��Ŀ����:ʵ��LFU(least frequently used)�㷨������Ƶ������̭cache��Ԫ�أ�Ƶ�����ٵ�Ԫ�ش�cache���Ƴ���ÿ��
//        ����һ��Ԫ�أ���Ԫ�صķ���Ƶ�ʼ�1
//�ⷨ����:�ýڵ��ʾ����ͬƵ�ʵ�key����hashtable��ʾkey��value������һ��hashtable��ʾkey��node*,��ʾ���key
//        ���ڵĽڵ㣬ÿһ��node����Ƶ���ź���

struct Node //�ڵ��ʾ������ͬ����Ƶ�ʵ�key
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
		if (values.find(key) != values.end())//�ڵ���ڣ���߷���Ƶ�� 
		{
			increaseCount(key);//��߷���Ƶ�ʣ����ܲ����µĽڵ�
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
		else //key������
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