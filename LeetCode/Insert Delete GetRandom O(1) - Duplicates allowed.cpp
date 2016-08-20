#include<vector>
#include<unordered_map>
#include<set>
//题目描述:设计一种数据结构，使得插入和删除的平均复杂度是O(1),允许重复元素，getRandom方法返回任意一个元素，
//        其概率与元素的个数成正比。
//解法描述:用vector保存每个元素，unordered_map保存每个元素以及下标，因为有重复元素，所以保存的下标必须是有序
//        的，只能用set
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

		if (last_val != val)//注意这里，要判断最后一个元素是否与当前元素相等，如果不相等才交换
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