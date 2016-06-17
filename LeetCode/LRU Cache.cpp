#include<list>
#include<unordered_map>
//题目描述：实现一个LRU cache算法，即Least Recently Used算法，最近没有被访问到的数据，之后被访问到的可能性就很低
//解法描述：CacheNode表示一个节点，包括key和value，用双向链表表示cache，一个hashtable表示每一个key到list中的元素，刚刚访问的元素放到链表前面，最后
//一个元素就是最不经常使用的元素。
class LRUCache
{
private:
	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v) : key(k), value(v){};
	};
	int capacity;  //cache的容量
	std::list<CacheNode> list;
	std::unordered_map<int, std::list<CacheNode>::iterator> cache; //每一个键对应的在链表的位置
public:
	LRUCache(int capacity) 
	{
		this->capacity = capacity;
	}

	int get(int key) 
	{
		if (cache.find(key) == cache.end()) // 没找到返回-1
			return -1;

		list.splice(list.begin(), list, cache[key]);
		cache[key] = list.begin();//更新迭代器
		return cache[key]->value;
	}

	void set(int key, int value) 
	{
		if (cache.find(key) == cache.end()) //该key不存在
		{
			if (list.size() == capacity) //cache已经满了
			{
				cache.erase(list.back().key); //把链表中的最后一个元素删掉
				list.pop_back();
			}
			list.push_front(CacheNode(key, value)); //插入到链表开头
			cache[key] = list.begin();
		}
		else
		{
			cache[key]->value = value;
			list.splice(list.begin(), list, cache[key]);
			cache[key] = list.begin();//更新迭代器
		}
	}
};
