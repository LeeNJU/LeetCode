#include<vector>
#include<unordered_map>
//题目描述:设计一种数据结构，使得插入和删除的平均复杂度都是O(1),并且能随机返回其中的元素。
//解法描述:vector保存所有元素，map保存元素以及下标，删除的时候，把要删除的元素和最后一个元素交换，然后删除，
//        也就是说总是删除最后一个元素

class RandomizedSet 
{
private:
	std::vector<int> nums;
	std::unordered_map<int, int> m;
public:
	/** Initialize your data structure here. */
	RandomizedSet() 
	{

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified 
	element. */
	bool insert(int val) 
	{
		if (m.find(val) != m.end()) 
			return false;
		
		nums.emplace_back(val);
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{
		if (m.find(val) == m.end()) 
			return false;
		
		int last = nums.back();//与最后一个元素交换
		m[last] = m[val];
		nums[m[val]] = last;
		nums.pop_back();
		m.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		return nums[rand() % nums.size()];
	}
};