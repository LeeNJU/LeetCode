#include<list>
#include<unordered_map>
//��Ŀ����:ʵ��һ��LRU cache�㷨����Least Recently Used�㷨�����û�б����ʵ������ݣ�֮�󱻷��ʵ��Ŀ�����
//         �ͺܵ�
//�ⷨ����:CacheNode��ʾһ���ڵ㣬����key��value����˫�������ʾcache��һ��hashtable��ʾÿһ��key��list��
//        ��Ԫ�أ��ոշ��ʵ�Ԫ�طŵ�����ǰ�棬���һ��Ԫ�ؾ��������ʹ�õ�Ԫ�ء�
class LRUCache
{
private:
	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v) : key(k), value(v){};
	};
	int capacity;  //cache������
	std::list<CacheNode> list;
	std::unordered_map<int, std::list<CacheNode>::iterator> cache; //ÿһ������Ӧ���������λ��
public:
	LRUCache(int capacity) 
	{
		this->capacity = capacity;
	}

	int get(int key) 
	{
		if (cache.find(key) == cache.end()) // û�ҵ�����-1
			return -1;

		list.splice(list.begin(), list, cache[key]);
		cache[key] = list.begin();//���µ�����
		return cache[key]->value;
	}

	void set(int key, int value) 
	{
		if (cache.find(key) == cache.end()) //��key������
		{
			if (list.size() == capacity) //cache�Ѿ�����
			{
				cache.erase(list.back().key); //�������е����һ��Ԫ��ɾ��
				list.pop_back();
			}
			list.push_front(CacheNode(key, value)); //���뵽����ͷ
			cache[key] = list.begin();
		}
		else
		{
			cache[key]->value = value;
			list.splice(list.begin(), list, cache[key]);
			cache[key] = list.begin();//���µ�����
		}
	}
};
