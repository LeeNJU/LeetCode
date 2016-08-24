#include<vector>
//题目描述:设计一种迭代器，包含peek(),next()和hasNext()方法，peek方法得到迭代器的下一个元素，但是并不改变
//        迭代器，例如[1,2,3,4],调用peek得到1，调用next还是得到1，再调用next得到2
//解法描述:提前缓存下一个元素，每次都要判断是否已经缓存了元素
class Iterator 
{
	struct Data;
	Data* data;
public:
	Iterator(const std::vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator 
{
private:
	bool cache;
	int value;
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums) 
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		cache = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() //判断是否有缓存元素
	{
		if (!cache)
		{
			value = Iterator::next();
			cache = true;
		}

		return value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
	{
		if (!cache)
			return Iterator::next();

		cache = false;
		return value;
	}

	bool hasNext() const 
	{
		if (cache)
			return true;

		return Iterator::hasNext();
	}
};