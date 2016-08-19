#include<vector>
#include<unordered_map>
//��Ŀ����:���һ�����ݽṹ��ʹ�ò����ɾ����ƽ�����Ӷȶ���O(1),����������������е�Ԫ�ء�
//�ⷨ����:vector��������Ԫ�أ�map����Ԫ���Լ��±꣬ɾ����ʱ�򣬰�Ҫɾ����Ԫ�غ����һ��Ԫ�ؽ�����Ȼ��ɾ����
//        Ҳ����˵����ɾ�����һ��Ԫ��

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
		
		int last = nums.back();//�����һ��Ԫ�ؽ���
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