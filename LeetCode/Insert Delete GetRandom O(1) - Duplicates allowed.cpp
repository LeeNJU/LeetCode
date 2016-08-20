#include<vector>
#include<unordered_map>
#include<set>
//��Ŀ����:���һ�����ݽṹ��ʹ�ò����ɾ����ƽ�����Ӷ���O(1),�����ظ�Ԫ�أ�getRandom������������һ��Ԫ�أ�
//        �������Ԫ�صĸ��������ȡ�
//�ⷨ����:��vector����ÿ��Ԫ�أ�unordered_map����ÿ��Ԫ���Լ��±꣬��Ϊ���ظ�Ԫ�أ����Ա�����±����������
//        �ģ�ֻ����set
class RandomizedCollection 
{
private:
	std::vector<int> vec;
	std::unordered_map<int, std::set<int>> map;

public:
	/** Initialize your data structure here. */
	RandomizedCollection() 
	{

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain 
	the specified element. */
	bool insert(int val) 
	{
		bool return_val = map.find(val) == map.end();
		map[val].insert(vec.size());
		vec.push_back(val);
		return return_val;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified 
	element. */
	bool remove(int val) 
	{
		if (map.find(val) == map.end() || map[val].size() == 0)
			return false;

		int last_val = vec.back();
		vec.pop_back();
		map[last_val].erase(vec.size());

		if (last_val != val)//ע�����Ҫ�ж����һ��Ԫ���Ƿ��뵱ǰԪ����ȣ��������ȲŽ���
		{
			int index = *map[val].begin();
			map[val].erase(index);
			vec[index] = last_val;
			map[last_val].insert(index);
		}

		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() 
	{
		return vec[rand() % vec.size()];
	}
};