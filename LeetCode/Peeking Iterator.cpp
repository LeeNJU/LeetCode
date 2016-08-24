#include<vector>
//��Ŀ����:���һ�ֵ�����������peek(),next()��hasNext()������peek�����õ�����������һ��Ԫ�أ����ǲ����ı�
//        ������������[1,2,3,4],����peek�õ�1������next���ǵõ�1���ٵ���next�õ�2
//�ⷨ����:��ǰ������һ��Ԫ�أ�ÿ�ζ�Ҫ�ж��Ƿ��Ѿ�������Ԫ��
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
	int peek() //�ж��Ƿ��л���Ԫ��
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